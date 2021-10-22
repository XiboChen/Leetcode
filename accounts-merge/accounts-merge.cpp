class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        vector<vector<string>> res;
        unordered_map<string, string> root;//email-email -> email-root
        unordered_map<string, string> owner;  //email-name
        unordered_map<string, set<string>> m; //root-<emails>
        for (auto account : accounts) {
            for (int i = 1; i < account.size(); ++i) {
                root[account[i]] = account[i];
                owner[account[i]] = account[0];
            }
        }
        
        //开始把 第一个邮箱设为第二个邮箱后面的root
        for(auto account:accounts){
            //这里对第一个也要找root，是以防第一个之前访问过了，root变掉了
            string r=find(account[1],root); 
            for(int i=2;i<account.size();++i){
                root[find(account[i],root)]=r;
            }
        }
        
        //把上面的结果反转一下，root对应各个email
        for(auto account:accounts){
            for(int i=1;i<account.size();++i){
                m[find(account[i],root)].insert(account[i]);
            }
        }
        for(auto i:m){
            vector<string> t(i.second.begin(),i.second.end());
            t.insert(t.begin(),owner[i.first]);
            res.push_back(t);
        }
        
        return res;
    }
    
    string find(string s,unordered_map<string, string>& root){
        return root[s]==s?s:find(root[s],root);
    }
};