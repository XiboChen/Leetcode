class Solution {
public:
    bool helper(string s, unordered_set<string>& sset,vector<int>& memo,int start){
        if(start>=s.size()) return true;
        if(memo[start]!=-1) return memo[start];
        for(int i=start;i<s.size();i++){
            string word=s.substr(start,i-start+1);
            if(sset.count(word) && helper(s,sset,memo,i+1)){
                memo[start]=1;
                return true;
            }
        }
        memo[start]=0;
        return false;
    }
    
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> sset(wordDict.begin(),wordDict.end());
        vector<int> memo(s.size(),-1);
        return helper(s,sset,memo,0);
    }
};