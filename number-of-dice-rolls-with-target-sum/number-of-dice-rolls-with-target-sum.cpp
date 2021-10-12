class Solution {
public:
    int numRollsToTarget(int d, int f, int target) {
        int M=1e9+7;
        vector<vector<int>> dp(d+1,vector<int>(target+1));
        dp[0][0]=1;
        for(int i=1;i<=d;++i){
            for(int j=1;j<=target;++j){
                for(int k=1;k<=f&&j>=k;++k){
                    dp[i][j]=(dp[i][j]+dp[i-1][j-k])%M;
                }
            }
        }
        return dp[d][target];
    }
};