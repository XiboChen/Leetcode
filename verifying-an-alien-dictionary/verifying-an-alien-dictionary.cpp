class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {
        vector<char> v(26);
        for(int i=0;i<26;++i){
            v[order[i]-'a']=i+'a';
        }
        for(int i=0;i<words.size();++i){
            for(int j=0;j<words[i].size();++j){
                words[i][j]=v[words[i][j]-'a'];
            }
            if(i>0&&words[i]<words[i-1]) return false;
        }
        return true;
    }
};