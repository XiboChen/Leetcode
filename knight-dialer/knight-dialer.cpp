class Solution {
public:
    int knightDialer(int n) {
        int res=0,mod=1e9+7;
        vector<vector<int>> dp(n,vector<int>(10));
        vector<vector<int>> path{{4,6},{6,8},{7,9},{4,8},{3,9,0},{},{1,7,0},{2,6},{1,3},{4,2}};
        for(int i=0;i<10;i++){
            dp[0][i]=1;
        }
        for(int i=1;i<n;i++){
            for(int j=0;j<10;j++){
                for(auto idx:path[j]){
                    dp[i][j]=(dp[i][j]+dp[i-1][idx])%mod;
                }
            }
        }
        for(int i=0;i<10;i++){
            res=(res+dp.back()[i])%mod;
        }
        return res;
    }
};

// 0 -> 4, 6
// 1 -> 6, 8
// 2 -> 7, 9
// 3 -> 4, 8
// 4 -> 3, 9, 0
// 5 ->
// 6 -> 1, 7, 0
// 7 -> 2, 6
// 8 -> 1, 3
// 9 -> 4, 2

// dp[i][j]:第i次跳到数字j时组成的不同号码的个数