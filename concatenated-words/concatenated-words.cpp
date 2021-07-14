class Solution {
public:
    vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
        unordered_set<string> sset(words.begin(),words.end());
        vector<string> res;
        // int min_=1000,max_=0;
        // for(int i=0;i<words.size();i++){
        //     int t=words[i].size();
        //     min_=min(min_,t);
        //     max_=max(max_,t);
        // }
        // vector<int> memo(max_,-1);
        for(int i=0;i<words.size();i++){
            string s=words[i];
            // if(s.size()<2*min_) continue;    //最小size为3，小于6就不可能有两个
            // if(helper(s,sset,memo,0,0)){  //有两个及以上组成
            //     res.push_back(s);
            // }
            if(helper(s,sset,0,0))
                res.push_back(s);
        }
        return res;
    }
    
    // bool helper(string& s,unordered_set<string>& sset,vector<int>& memo,int start,int cnt){
    bool helper(string& s,unordered_set<string>& sset,int start,int cnt){
        if(start>=s.size() &&cnt>=2) return true;
        // if(memo[start]!=-1) return memo[start];
        for(int i=start;i<s.size();i++){
            string word=s.substr(start,i-start+1);
            // if(sset.count(word) && helper(s,sset,memo,i+1,cnt+1)){
            if(sset.count(word) && helper(s,sset,i+1,cnt+1)){
                // memo[start]=1;
                return true;
            }
        }
        // memo[start]=0;
        return false;
    }
};