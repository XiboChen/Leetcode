class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum=accumulate(nums.begin(),nums.end(),0);
        if(sum%2==1) return false;
        int target=sum/2;
        vector<int> dp(target+1,0);
        dp[0]=true;
        for(auto num:nums){
            for(int i=target;i>=num;--i){
                dp[i]=dp[i]||dp[i-num];
            }
        }
        return dp[target];
    }
};