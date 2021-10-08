class Solution {
public:
    vector<string> subdomainVisits(vector<string>& cpdomains) {
        unordered_map<string,int> m;  //domain-times
        for(auto cpd:cpdomains){
            auto pos=cpd.find(' ');
            string time=cpd.substr(0,pos);
            string domain=cpd.substr(pos+1);
            for(int i=0;i<domain.size();++i){
                if(domain[i]=='.'){
                   m[domain.substr(i+1)]+=stoi(time); 
                }
            }
            m[domain]+=stoi(time);
        }
        vector<string> res;
        for(auto i:m){
            res.push_back(to_string(i.second)+" "+i.first);
        }
        return res;
    }
};