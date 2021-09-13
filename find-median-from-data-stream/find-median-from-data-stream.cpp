class MedianFinder {
public:
    /** initialize your data structure here. */
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        if(max_h.empty()||num<max_h.top()){
            max_h.push(num);
        }else min_h.push(num);
        
        if(min_h.size()>max_h.size()){
            max_h.push(min_h.top());min_h.pop();
        }
        else if(max_h.size()-min_h.size()==2){
            min_h.push(max_h.top());
            max_h.pop();
        }
    }
    
    double findMedian() {
        if(max_h.size()>min_h.size()) return (double)(max_h.top());
        else return ((double)(max_h.top())+(double)(min_h.top()))/2;
    }
private:
    priority_queue<int,vector<int>,greater<int>> min_h;
    priority_queue<int,vector<int>,less<int>> max_h;
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */