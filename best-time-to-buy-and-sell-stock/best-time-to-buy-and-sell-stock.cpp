class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        int dp[n],max_=0,res=0;
        dp[0]=0;
        for(int i=1;i<n;++i){
            dp[i]=prices[i]-prices[i-1];
            max_=max(dp[i],dp[i]+max_);
            res=max(res,max_);
        }
        return res;
    }
};