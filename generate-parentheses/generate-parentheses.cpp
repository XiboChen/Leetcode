class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        dfs(res,"",n,n);
        return res;
    }
    
    void dfs(vector<string>& res,string cur,int l,int r){
        if(l+r==0){
            res.push_back(cur);
            return;
        }
        if(l>r) return;
        if(l>0){
            cur+='(';
            dfs(res,cur,l-1,r);
            cur.pop_back();
        }
        if(r>0){
            cur+=')';
            dfs(res,cur,l,r-1);
            cur.pop_back();
        }
    }
};