class Solution {
public:
    int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
        int n=stations.size();
        vector<long> dp(n+1,startFuel);
        for(int k=0;k<n;++k){
            for(int j=k;j>=0&&dp[j]>=stations[k][0];--j){
                dp[j+1]=max(dp[j+1],dp[j]+stations[k][1]);
            }
        }
        for(int i=0;i<=n;++i){
            if(dp[i]>=target) return i;
        }
        return -1;
    }
};