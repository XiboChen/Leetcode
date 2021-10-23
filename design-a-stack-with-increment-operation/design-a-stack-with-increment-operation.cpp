class CustomStack {
public:
    CustomStack(int maxSize) {
        size_=maxSize;
    }
    
    void push(int x) {
        if(v.size()<size_){
            v.push_back(x);
        }
    }
    
    int pop() {
        if(v.empty()) return -1;
        int res=v.back();
        v.pop_back();
        return res;
    }
    
    void increment(int k, int val) {
        if(v.empty())  return;
        if(k<v.size()){
            for(int i=0;i<k;++i)
                v[i]+=val;
        }else if(k>=v.size()){
            for(int i=0;i<v.size();++i)
                v[i]+=val;
        }
    }
private:
    int size_;
    vector<int> v;
};

/**
 * Your CustomStack object will be instantiated and called as such:
 * CustomStack* obj = new CustomStack(maxSize);
 * obj->push(x);
 * int param_2 = obj->pop();
 * obj->increment(k,val);
 */