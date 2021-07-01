class Solution {
public:
    int minDifficulty(vector<int>& jobDifficulty, int d) {
        int n=jobDifficulty.size();
        if(n<d) return -1;
        vector<vector<int>> dp(d,vector<int>(n,300*1000));
        //初始化
        int maxV=0;
        for(int j=0;j<n;j++){   //第0天完成0项,1项...任务的。。
            maxV=max(maxV,jobDifficulty[j]);
            dp[0][j]=maxV;
        }
        for(int i=1;i<d;i++){
            for(int j=i;j<n;j++){
                int maxV=jobDifficulty[j];
                for(int k=j-1;k>=i-1;k--){
                    maxV=max(maxV,jobDifficulty[k+1]);
                    dp[i][j]=min(dp[i][j],dp[i-1][k]+maxV);
                }
            }
        }
        return dp.back().back();
    }
};

/*
dp[0][D] 从index为0开始，切D刀
dp[i][j] min difficulties to schedule jobs 1~j in i days; 
         前i天完成j项工作的最小难度和  j>=i
         dp[i][j]=dp[i-1][k]+max(job[k+1],job[k+2],...,job[k]);i-1<=k<j
         

*/