class LRUCache {
public:
    LRUCache(int capacity) {
        cap=capacity;
    }
    
    int get(int key) {
        auto it=m.find(key);
        if(it==m.end()) return -1;
        l.splice(l.begin(),l,it->second);
        return it->second->second;
    }
    
    void put(int key, int value) {
        auto it=m.find(key);
        if(it!=m.end())  //find
            l.erase(it->second);
        l.push_front({key,value});
        m[key]=l.begin();
        
        if(l.size()>cap){
            m.erase(l.back().first);
            l.pop_back();
        }
    }
private:
    int cap;
    list<pair<int,int>> l;
    unordered_map<int,list<pair<int,int>>::iterator> m;
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */