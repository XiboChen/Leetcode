class Solution {
public:
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        unordered_map<string,vector<string>> m;
        for(auto pro:products){
            string t="";
            for(auto ch:pro){
                t+=ch;
                m[t].push_back(pro);
            }
        }
        vector<vector<string>> res;
        string tmp="";
        for(int i=0;i<searchWord.size();++i){
            vector<string> one;
            tmp+=searchWord[i];
            sort(m[tmp].begin(),m[tmp].end());
            if(m[tmp].size()>3){
                for(int i=0;i<3;++i)
                    one.push_back(m[tmp][i]);
                res.push_back(one);
            }else res.push_back(m[tmp]);
        }
        return res;
    }
};