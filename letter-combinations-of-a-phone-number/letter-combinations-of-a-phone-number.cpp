class Solution {
public:
    vector<string> letterCombinations(string digits) {
        if(digits.size()==0) return {};
        vector<vector<char>> let{{},{},{'a','b','c'},{'d','e','f'},{'g','h','i'},{'j','k','l'},{'m','n','o'},{'p','q','r','s'},{'t','u','v'},{'w','x','y','z'}};
        vector<string> res;
        dfs(digits,res,let,"",0);
        return res;
    }
    
    void dfs(string& digits,vector<string>& res,vector<vector<char>>& let,string cur,int i){
        if(i==digits.size()){
            res.push_back(cur);
            return;
        }
        for(auto k:let[digits[i]-'0']){
            cur+=k;
            dfs(digits,res,let,cur,i+1);
            cur.pop_back();
        }
    }
};