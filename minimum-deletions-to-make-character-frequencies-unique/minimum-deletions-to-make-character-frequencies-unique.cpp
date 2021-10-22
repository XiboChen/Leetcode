class Solution {
public:
    int minDeletions(string s) {
        int res=0;
        vector<int> v(26);
        for(auto ch:s) ++v[ch-'a']; 
        
        unordered_set<int> st;
        for(auto it:v){
            
                while(it>0&&!st.insert(it).second){
                    --it;
                    ++res;
                    //cout<<it.first<<" "<<it.second<<" "<<res<<endl;
                }
                st.insert(it);
            
        }
        
        return res;
    }
};