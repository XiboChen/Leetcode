class Solution {
public:
    int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
        int n=stations.size();
        vector<long> dp(n+1,startFuel);
        for(int k=0;k<n;++k){
            for(int i=k;i>=0&&dp[i]>=stations[k][0];--i){ //好歹现在的距离能到下一个station
                dp[i+1]=max(dp[i+1],dp[i]+stations[k][1]);
            }
        }
        for(int i=0;i<=n;++i){
            if(dp[i]>=target) return i;
        }
        return -1;
    }
};