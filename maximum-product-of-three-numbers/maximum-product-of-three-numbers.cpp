class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        int t=nums[0]*nums[1]*nums[n-1];
        return max(t,nums[n-1]*nums[n-2]*nums[n-3]);
    }
};