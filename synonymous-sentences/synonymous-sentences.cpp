class Solution {
public:
    vector<string> generateSentences(vector<vector<string>>& synonyms, string text) {
        unordered_map<string,vector<string>> m;
        for(auto s:synonyms){
            m[s[0]].push_back(s[1]);
            m[s[1]].push_back(s[0]);
        }
            
        vector<string> v;
        stringstream ss(text);
        string s;
        while (std::getline(ss, s, ' ')) {
            v.push_back(s);
        }
        
        vector<string> res;
        
        dfs(res,m,v,0,"");
        sort(res.begin(),res.end());
        return res;
    }
    
    void dfs(vector<string>& res, unordered_map<string,vector<string>>& m,vector<string>& words,int idx,const string& sentence){
        if(idx==words.size()){
            res.push_back(sentence);
            return;
        }
        if(m.count(words[idx])){
            unordered_set<string> visited;
            vector<string> syn;
            dddddfs(m,words[idx],visited,syn); //所有words[idx]的同义词都存进了syn里
            
            for(auto s:syn){
                dfs(res,m,words,idx+1,(sentence.empty()?"":sentence+" ")+s);
            }
            
        }else{
            dfs(res,m,words,idx+1,(sentence.empty()?"":sentence+" ")+words[idx]);
        }
    }
    
    void dddddfs(unordered_map<string,vector<string>>& m,const string& word,unordered_set<string>& visited,vector<string>& syn){
        syn.push_back(word);
        visited.insert(word);
        for(auto s:m[word]){
            if(!visited.count(s)){
                dddddfs(m,s,visited,syn);
            }
        }
    }
};