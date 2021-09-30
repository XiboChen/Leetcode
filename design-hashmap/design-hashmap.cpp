class MyHashMap {
public:
    MyHashMap() {
        v.resize(1001,vector<int>());
    }
    
    void put(int key, int value) {
        int hashkey=key%1000;
       if(v[hashkey].empty())
           v[hashkey].resize(1001,-1);
        v[hashkey][key/1000]=value;
    }
    
    int get(int key) {
        int hashkey=key%1000;
        if(!v[hashkey].empty())
            return v[hashkey][key/1000];
        return -1;
    }
    
    void remove(int key) {
        int hashkey=key%1000;
        if(!v[hashkey].empty())
            v[hashkey][key/1000]=-1;
    }
private:
    vector<vector<int>> v;
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */