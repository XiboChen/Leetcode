class Solution {
public:
    int maxArea(vector<int>& height) {
        int max_=0;
        int n=height.size(),lo=0,hi=n-1;
        while(lo<hi){
            max_=max(max_,(hi-lo)*min(height[hi],height[lo]));
            if(height[lo]<height[hi]) ++lo;
            else --hi;
        }
        return max_;
    }
};