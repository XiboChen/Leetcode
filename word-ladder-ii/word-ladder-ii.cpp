class Solution {
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        vector<vector<string>> res;
        vector<string> v{beginWord};
        unordered_set<string> wordset(wordList.begin(),wordList.end());
        if(!wordset.count(endWord)) return {};
        queue<vector<string>> q;
        q.push(v);
        int level=1,minlevel=INT_MAX;    //大于minlevel的就不走了，省时间
        unordered_set<string> words;    //用来记录已经循环过的路劲中的词
        while(!q.empty()){
            for(int i=q.size();i>0;--i){
                auto t=q.front();q.pop();
                if(t.size()>level){      //t是一个vector string
                    for(string w:words) wordset.erase(w);
                    words.clear();
                    level=t.size();
                    if(level>minlevel) break;
                }
                string last=t.back();
                for(int i=0;i<last.size();i++){
                    string newlast=last;
                    for(int j='a';j<='z';j++){
                        newlast[i]=j; 
                        if(!wordset.count(newlast)) continue;
                        words.insert(newlast);
                        vector<string> nextpath=t;
                        nextpath.push_back(newlast);
                        if(newlast==endWord){
                            res.push_back(nextpath);
                            minlevel=level;
                        }else q.push(nextpath);
                    }
                }
            }
        }
        return res;
    }
};