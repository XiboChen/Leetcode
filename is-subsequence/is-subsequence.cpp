class Solution {
public:
    bool isSubsequence(string s, string t) {
        int i=0,j=0,m=s.size(),n=t.size();
        while(i<m&&j<n){
            while(s[i]!=t[j]){
                ++j;
                if(j==n) return false;
            }
            ++i;++j;
        }
        return i==m;
    }
};