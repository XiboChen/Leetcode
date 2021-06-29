class LFUCache {
public:
    LFUCache(int capacity) {
        cap=capacity;
    }
    
    int get(int key) {
        // 1. 如果m中不存在5，那么返回-1
        if(!m.count(key)) return -1;
        // 2. 从freq中频率为1的list中将5删除
        freq[m[key].second].erase(iter[key]); //(需要删除坐标，用上了iter map)
        // 3. 将m中5对应的frequence值自增1
        m[key].second++;
        // 4. 将5保存到freq中频率为2的list的末尾
        freq[m[key].second].push_back(key);
        // 5. 在iter中保存5在freq中频率为2的list中的位置
        iter[key]=--freq[m[key].second].end();
        // 6. 如果freq中频率为minFreq的list为空，minFreq自增1
        if(freq[minfreq].size()==0) minfreq++;
        // 7. 返回m中5对应的value值
        return m[key].first;
    }
    
    void put(int key, int value) {
        if(cap<=0) return;
        // 1. 如果调用get(7)返回的不是-1，存在key了，更新当前value，并返回
        if(get(key)!=-1){
            m[key].first=value;
            return;
        } 
        // 2. 如果此时m的大小大于了cap，即超过了cache的容量，则：
        if(m.size()>=cap){
        // a）在m中移除minFreq对应的list的首元素的纪录，即移除4 -> {value4, 1}
            m.erase(freq[minfreq].front());
        // b）在iter中清除4对应的纪录，即移除4 -> list.begin()
            iter.erase(freq[minfreq].front());
        // c）在freq中移除minFreq对应的list的首元素，即移除4
            freq[minfreq].pop_front();
        }
        // 3. 在m中建立7的映射，即 7 -> {value7, 1}
        m[key]={value,1};
        // 4. 在freq中频率为1的list末尾加上7
        freq[1].push_back(key);
        // 5. 在iter中保存7在freq中频率为1的list中的位置
        iter[key]=--freq[1].end();
        // 6. minFreq重置为1
        minfreq=1;
    }
private:
    unordered_map<int,pair<int,int>> m; //num,出现的次数
    map<int,list<int>> freq; //把相同频率的num放在一起
    map<int,list<int>::iterator> iter; // num,freq中的key位置
    int cap;
    int minfreq;
};
/*
m:                     (get 5 后)                        (put 7)
5 -> {value5, 1}            5 -> {value5, 2}            5 -> {value5, 2}
4 -> {value4, 1}            4 -> {value4, 1}            7 -> {value7, 1} 

freq:                       freq:                       freq:
1 -> {5，4}                 1 -> {4}      2 -> {5}      1 -> {7}      2 -> {5}   
                            
iter:                       iter:                       iter:  
4 -> list.begin() + 1       4 ->list.begin()            7 ->list.begin()
5 -> list.begin()           5 ->list.begin()            5 ->list.begin()

m中5对应的频率为1，4对应的频率为1，然后freq中频率为1的有4和5。iter中是key所在freq中对应链表中的位置的iterator。
*/
// LFU-least frequentlu used 和LRU-least recently used不同
// 比如，cache大小为3，依次存入5，4，5，4，5，7，满了，LRU要删除4，LFU删除7