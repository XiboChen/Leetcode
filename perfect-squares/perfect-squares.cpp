class Solution {
public:
    int numSquares(int n) {
        vector<int> dp(n+1,INT_MAX);
        dp[0]=0;
        for(int num=1;num<=sqrt(n);++num){
            for(int j=0;j<=n;++j){
                if(num*num<=j){
                    dp[j]=min(dp[j],dp[j-num*num]+1);
                }
            }
        }
        return dp[n];
    }
};