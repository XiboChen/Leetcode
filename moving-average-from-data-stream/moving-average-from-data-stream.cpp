class MovingAverage {
public:
    /** Initialize your data structure here. */
    MovingAverage(int size) {
        _size=size;
    }
    
    double next(int val) {
        nums.push_back(val);
        if(nums.size()>_size){
            nums.erase(nums.begin()+0);
        }
        int sum=0,t=0;
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
            t=i;
        }
        return (double)sum/(double)(t+1);
    }
private:
    int _size;
    vector<int> nums;
    
};

/**
 * Your MovingAverage object will be instantiated and called as such:
 * MovingAverage* obj = new MovingAverage(size);
 * double param_1 = obj->next(val);
 */