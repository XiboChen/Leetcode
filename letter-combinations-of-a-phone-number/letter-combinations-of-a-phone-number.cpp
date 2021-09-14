class Solution {
public:
    vector<string> letterCombinations(string digits) {
        if(digits.size()==0) return {};
        vector<string> res;
        vector<vector<char>> v{{},{},{'a','b','c'},{'d','e','f'},{'g','h','i'},{'j','k','l'},{'m','n','o'},{'p','q','r','s'},{'t','u','v'},{'w','x','y','z'}};
        string t;         
        dfs(digits,res,v,t,0);
        return res;
    }
    
    void dfs(string digits,vector<string>& res,vector<vector<char>>& v,string& t, int i){
        if(i==digits.size()){
            res.push_back(t);
            return;
        }
       
        for(auto k:v[digits[i]-'0']){
            t+=k;
            dfs(digits,res,v,t,i+1);
            t.pop_back();
        }        
    }
};