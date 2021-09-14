class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        string cur;
        dfs(n,res,cur,0,0);
        return res;
    }
    
    void dfs(int& n, vector<string>& res,string& cur, int l,int r){
        if(l+r==2*n){
            res.push_back(cur);
            return;
        }
        if(r>l) return; 
        if(l<n){
            dfs(n,res,cur+='(',l+1,r);
            cur.pop_back();
        }
        if(r<n){
            dfs(n,res,cur+=')',l,r+1);
            cur.pop_back();
        }
    }
};