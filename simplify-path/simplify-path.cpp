class Solution {
public:
    string simplifyPath(string path) {
        string res,t;
        stringstream str;
        str<<path;
        vector<string> v;
        while(getline(str,t,'/')){
            if(t==""||t==".") continue;
            if(t==".."&&!v.empty()) v.pop_back();
            else if(t!="..") v.push_back(t);
        }
        for(auto i:v) res+="/"+i;
        return res.empty()?"/":res;
    }
};