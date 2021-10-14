class Solution {
public:
    int minDistance(string word1, string word2) {
        int m=word1.size(),n=word2.size();
        vector<vector<int>> memo(m,vector<int>(n));
        return helper(word1,m-1,word2,n-1,memo);
    }
    
    int helper(string& word1,int i, string& word2,int j,vector<vector<int>>& memo){
        if(i==-1) return j+1;
        if(j==-1) return i+1;
        if(memo[i][j]>0) return memo[i][j];
        int res=0;
        if(word1[i]==word2[j])
            return helper(word1,i-1,word2,j-1,memo);
        else{
            int insert=helper(word1,i,word2,j-1,memo);
            int delet=helper(word1,i-1,word2,j,memo);
            int rep=helper(word1,i-1,word2,j-1,memo);
            res=min(insert,min(delet,rep))+1;
        }
        return memo[i][j]=res;
    }
};