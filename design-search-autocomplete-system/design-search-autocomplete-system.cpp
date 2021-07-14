class AutocompleteSystem {
public:
    AutocompleteSystem(vector<string>& sentences, vector<int>& times) {
        for(int i=0;i<times.size();i++){
            m[sentences[i]]+=times[i];
        }
        data="";
    }
    
    struct cmp{
        bool operator()(pair<string,int>& a,pair<string,int>& b){
            return a.second>b.second || (a.second==b.second&&a.first<b.first);
        }
    };
    
    vector<string> input(char c) {
        if(c=='#'){
            m[data]++;
            data="";
            return {};
        }
        data.push_back(c); //或append都可以加一个character
        priority_queue<pair<string,int>,vector<pair<string,int>>,cmp> q;
        for(auto onepair:m){
            bool flag=true;
            for(int i=0;i<data.size();i++){
                if(data[i]!=onepair.first[i]){
                    flag=false;
                    break;
                }
            }
            if(flag){
                q.push(onepair);
                if(q.size()>3) q.pop();
            }
        }
        vector<string> res(q.size());
        for(int i=q.size()-1;i>=0;i--){
            res[i]=q.top().first;q.pop();
        }
        return res;
    }
private:
    unordered_map<string,int> m;
    string data;
    /*
    1.需要hashmap建立句子和出现频率的隐射，
    2.需要字符串data保存之前输入过的字符
    
    input中
    1.首先判断是否为#，是则为一个完整的句子，hashmap次数+1，data清空，返回空。
    2.否则将当前字符加入data，
    3.优先队列保存使用频率最高的三个，最小堆，pop出频率低的，
    4.首先遍历map中所有句子，验证当前字符串是否是前缀，若不符合，flag为false，break
    5.若flag为true，加入优先队列，
    */
};

/**
 * Your AutocompleteSystem object will be instantiated and called as such:
 * AutocompleteSystem* obj = new AutocompleteSystem(sentences, times);
 * vector<string> param_1 = obj->input(c);
 */