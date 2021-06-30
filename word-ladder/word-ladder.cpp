class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> wordset(wordList.begin(),wordList.end());
        if(!wordset.count(endWord)) return 0;
        queue<string> q;
        q.push(beginWord);
        int step=0,l=beginWord.size();
        while(!q.empty()){
            ++step;
            for(int i=q.size();i>0;--i){
                auto t=q.front();q.pop();
                for(int i=0;i<l;i++){           //遍历每个单词的每一位
                    char ch=t[i];
                    for(int j='a';j<='z';j++){
                        t[i]=j;
                        if(t==endWord) return step+1;
                        if(!wordset.count(t)) continue;
                        wordset.erase(t);
                        q.push(t);
                    }
                    t[i]=ch;          //变回去
                }
            }
        }
        return 0;
    }
};