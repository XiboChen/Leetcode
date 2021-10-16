class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        int m=matrix.size();
        if(m==0) return 0;
        int n=matrix[0].size();
        
        vector<vector<int>> dp(m,vector<int>(n));
        for(int i=0;i<m;++i){   //得到每一行最长的矩形
            for(int j=0;j<n;++j){
                dp[i][j]=(matrix[i][j]=='1')?(j==0?1:dp[i][j-1]+1):0;
            }
        }
        // for(auto i:dp){
        //     for(auto j:i) cout<<j<<" ";cout<<endl;
        // }
        int res=0;
        for(int i=0;i<m;++i){  //以每一行作为矩形最上面的边
            for(int j=0;j<n;++j){  //以每一行的某一列的点作为矩形的左上角
                int len=INT_MAX;
                for(int k=i;k<m;++k){
                    len=min(len,dp[k][j]);
                    if(len==0) break;
                    res=max(res,len*(k-i+1));
                }
            }
            
        }
        
        return res;
    }
};
















