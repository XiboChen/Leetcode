class Solution {
public:
    vector<string> subdomainVisits(vector<string>& cpdomains) {
        unordered_map<string,int> m;
        for(auto domain:cpdomains){
            auto it=domain.find(' ');
            int time=stoi(domain.substr(0,it));
            string web=domain.substr(it+1);
            while(1){
                m[web]+=time;
                auto i=web.find('.');
                if(i==string::npos) break;
                web=web.substr(i+1);
            }
        }
        vector<string> res;
        for(auto i:m){
            res.push_back(to_string(i.second)+" "+i.first);
        }
        return res;
    }
};