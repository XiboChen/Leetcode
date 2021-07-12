class Solution {
public:
    int findShortestSubArray(vector<int>& nums) {
        int n=nums.size(),res=INT_MAX,degree=0;
        unordered_map<int,int> freq;
        unordered_map<int,pair<int,int>> pos;

        for(int i=0;i<n;++i){
            if(++freq[nums[i]]==1)
                pos[nums[i]]={i,i};
            else 
                pos[nums[i]].second=i;
            
            degree = max(degree,freq[nums[i]]);
        }
        // for(auto it=m.begin();it!=m.end();it++){
        //     cout<<it->first<<" "<<it->second.first<<" "<<it->second.second<<endl;
        // }
       for(auto i:freq){
           if(degree==i.second){
               res=min(res,pos[i.first].second-pos[i.first].first+1);
           }
       }
        return res;
    }
};