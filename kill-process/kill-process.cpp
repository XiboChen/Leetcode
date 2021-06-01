class Solution {
public:
    void helper(int kill, unordered_map<int,vector<int>>& m,vector<int>& res){
        res.push_back(kill);
        for(auto t:m[kill]){
            helper(t,m,res);
        }
    }
    
    vector<int> killProcess(vector<int>& pid, vector<int>& ppid, int kill) {
        unordered_map<int,vector<int>> m;
        vector<int> res;
        for(int i=0;i<pid.size();i++){
            m[ppid[i]].push_back(pid[i]);
        }
        helper(kill,m,res);
        return res;
    }
};