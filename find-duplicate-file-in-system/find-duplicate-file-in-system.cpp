class Solution {
public:
    vector<vector<string>> findDuplicate(vector<string>& paths) {
        vector<vector<string>> res;
        unordered_map<string,vector<string>> m;
        for(auto path:paths){
            istringstream is(path);
            string pre="",t="";
            is>>pre;
            while(is>>t){
                int idx=t.find_last_of('(');
                string dir=pre+"/"+t.substr(0,idx);
                string cont=t.substr(idx+1,t.size()-idx-2);
                m[cont].push_back(dir);
            }
        }
        
        for(auto it:m){
            if(it.second.size()>1)
                res.push_back(it.second);
        }
        
        return res;
    }
};