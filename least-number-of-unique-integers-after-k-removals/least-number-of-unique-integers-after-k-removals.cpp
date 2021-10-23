class Solution {
public:
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
        unordered_map<int,int> m;
        for(auto a:arr) ++m[a];
        
        vector<pair<int,int>> v(m.begin(),m.end());
        sort(v.begin(),v.end(),[](pair<int,int>& a,pair<int,int>& b){
            return a.second<b.second;
        });
        int res=v.size();
        
        for(auto i:v){
            if(k>=i.second){
                --res;
                k-=i.second;
            }else break;
        }
        
        return res;
    }
};