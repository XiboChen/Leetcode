class Solution {
public:
    string longestPalindrome(string s) {
        int n=s.size(),max_len=1,left=0;
    
        vector<vector<bool>> dp(n,vector<bool>(n,false));
        for(int i=0;i<n;++i){
            dp[i][i]=true;
            for(int j=0;j<i;++j){
                dp[j][i]=(s[i]==s[j]&&(i-j<2||(i-j>=2&&dp[j+1][i-1])));
                if(dp[j][i]&&(i-j+1>max_len)){
                    max_len=i-j+1;
                    left=j;
                }
            }
        }
        return s.substr(left,max_len);
    }
};