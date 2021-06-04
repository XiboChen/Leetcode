class WordDistance {
public:
    WordDistance(vector<string>& wordsDict) {
        for(int i=0;i<wordsDict.size();i++){
            m[wordsDict[i]].push_back(i);
        }
    }
    
    int shortest(string word1, string word2) {
        int res=INT_MAX;
        for(int i=0;i<m[word1].size();i++){
            for(int j=0;j<m[word2].size();j++){
                res=min(res,abs(m[word1][i]-m[word2][j]));
            }
        }
        return res;
    }
private:
    unordered_map<string,vector<int>> m;
};

/**
 * Your WordDistance object will be instantiated and called as such:
 * WordDistance* obj = new WordDistance(wordsDict);
 * int param_1 = obj->shortest(word1,word2);
 */