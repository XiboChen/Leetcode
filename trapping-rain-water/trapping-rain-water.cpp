class Solution {
public:
    int trap(vector<int>& height) {
        int res=0,n=height.size(),max_=0;
        vector<int> left(n,0);
        vector<int> right(n,0);
        for(int i=1;i<n;++i){
            max_=max(max_,height[i-1]);
            left[i]=max(left[i-1],max_);
        }
        max_=0;
        for(int i=n-2;i>=0;--i){
            max_=max(max_,height[i+1]);
            right[i]=max(right[i+1],max_);
        }
        for(int i=0;i<n;++i){
            int t=min(left[i],right[i]);
            if(t>height[i]){
                res+=t-height[i];
            }
        }
        return res;
    }
};