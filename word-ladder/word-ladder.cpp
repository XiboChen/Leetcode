class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> wordset(wordList.begin(),wordList.end());
        if(!wordset.count(endWord)) return 0;
        queue<string> q{{beginWord}};
        int res=0;
        while(!q.empty()){
            ++res;
           
            for(int j=q.size();j>0;--j){
                string w=q.front();q.pop();
                for(int i=0;i<w.size();++i){
                    string neww=w;
                    for(int k='a';k<='z';++k){
                        neww[i]=k;
                        if(neww==endWord) return res+1;
                        if(!wordset.count(neww)) continue;
                        q.push(neww);
                        wordset.erase(neww);
                    }
                    neww=w;
                }
            }
        }
        return 0;
    }
};