class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {
        unordered_map<char,int> m;
        for(int i=0;i<order.size();++i){
            m[order[i]]=i;
        }
        for(int i=0;i<words.size();++i){
            for(int j=0;j<words[i].size();++j){
                words[i][j]=m[words[i][j]];
            }
            if(i>0&&words[i]<words[i-1]) return false;
        }
        return true;
    }
};