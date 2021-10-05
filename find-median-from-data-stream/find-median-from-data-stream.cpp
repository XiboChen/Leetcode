class MedianFinder {
public:
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        if(dading.empty()||num<dading.top()){
            dading.push(num);
        }
        else xiaoding.push(num);
        
        if(xiaoding.size()>dading.size()){
            dading.push(xiaoding.top());
            xiaoding.pop();
        }
        else if(dading.size()-xiaoding.size()>1){
            xiaoding.push(dading.top());
            dading.pop();
        }
    }
    
    double findMedian() {
        if(dading.size()>xiaoding.size())
            return dading.top();
        else return (double(dading.top())+double(xiaoding.top()))/2;
    }
private:
    priority_queue<int> dading;
    priority_queue<int,vector<int>,greater<int>> xiaoding;
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */