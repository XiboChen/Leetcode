class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        int res=0;
        unordered_set<string> wordset(wordList.begin(),wordList.end());
        if(!wordset.count(endWord)) return 0;
        
        queue<string> q{{beginWord}};
        while(!q.empty()){
            ++res;
            for(int i=q.size();i>0;--i){
                auto t=q.front();q.pop();
                
                for(int j=0;j<t.size();++j){
                    string neww=t;
                    for(int k='a';k<='z';++k){
                        neww[j]=k;
                        if(neww==endWord) return res+1;
                        if(!wordset.count(neww)) continue;
                        wordset.erase(neww);
                        q.push(neww);
                    }
                   
                }
            }
        }
        return 0;
    }
};