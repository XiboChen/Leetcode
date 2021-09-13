class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int max_=nums[0],cur=nums[0];
        for(int i=1;i<nums.size();++i){
            cur=max(nums[i],nums[i]+cur);
            max_=max(max_,cur);
        }
        return max_;
    }
};