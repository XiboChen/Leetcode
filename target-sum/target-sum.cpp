class Solution {
public:
    // int findTargetSumWays(vector<int>& nums, int target) {
    //     int sum=accumulate(nums.begin(),nums.end(),0);
    //     if((sum+target)%2!=0||sum<target) return 0;
    //     int tar=(sum+target)/2;
    //     vector<int> dp(tar+1);
    //     dp[0]=1;
    //     for(auto num:nums){
    //         for(int i=tar;i>=num;--i){
    //             dp[i]+=dp[i-num];
    //         }
    //     }
    //     return dp[tar];
    // }

    int findTargetSumWays(vector<int>& nums, int target) {
        int sum = 0;
        for (int& num : nums) {
            sum += num;
        }
        int diff = sum - target;
        if (diff < 0 || diff % 2 != 0) {
            return 0;
        }
        int neg = diff / 2;
        vector<int> dp(neg + 1);
        dp[0] = 1;
        for (int& num : nums) {
            for (int j = neg; j >= num; j--) {
                dp[j] += dp[j - num];
            }
        }
        return dp[neg];
    }

};