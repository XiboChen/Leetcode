class Solution {
public:
    int maxProduct(vector<int>& nums) {
        vector<int> hi(nums.size()), lo(nums.size());
        hi[0]=nums[0];lo[0]=nums[0];
        int res=nums[0];
        for(int i=1;i<nums.size();i++){
            hi[i]=max(nums[i],max(hi[i-1]*nums[i],lo[i-1]*nums[i]));
            lo[i]=min(nums[i],min(hi[i-1]*nums[i],lo[i-1]*nums[i]));
            res=max(res,hi[i]);
        }
        return res;
    }
};