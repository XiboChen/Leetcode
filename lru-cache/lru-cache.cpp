class LRUCache {
public:
    LRUCache(int capacity) {
        cap=capacity;
    }
    
    int get(int key) {
        auto t=m.find(key);
        if(t==m.end()) return -1;
        l.splice(l.begin(),l,t->second);
        return t->second->second;
    }
    
    void put(int key, int value) {
        auto t=m.find(key);
        if(t==m.end()){
            l.push_front({key,value});
            m[key]=l.begin();
        }
        else{
            l.erase(t->second);
            l.push_front({key,value});
            m[key]=l.begin();;
        }
        if(l.size()>cap){
            auto tmp=l.back();
            l.pop_back();
            m.erase(tmp.first);
        }
    }
    
private:
    int cap;
    list<pair<int,int>> l;
    //list<pair<int,int>>::iterator it;
    unordered_map<int,list<pair<int,int>>::iterator> m;
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */