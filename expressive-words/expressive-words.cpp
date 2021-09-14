class Solution {
public:
    int expressiveWords(string s, vector<string>& words) {
        int res=0,m=s.size(),n=words.size();
        for(string word:words){
            int i=0,j=0;
            while(i<m){
                if(j<word.size()&&s[i]==word[j]) ++j;
                else if(i>0&&s[i]==s[i-1]&&i+1<m&&s[i]==s[i+1]) ++i;
                else if(!(i>1&&s[i]==s[i-1]&&s[i]==s[i-2])) break;
                ++i;
            }
            if(i==m&&j==word.size()) ++res;
        }
        return res;
    }
};