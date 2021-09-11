class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int cur_sum=0,res=0;
        unordered_map<int,int> m{{0,1}};
        for(auto num:nums){
            cur_sum+=num;
            res+=m[cur_sum-k];
            ++m[cur_sum];
        }
        return res;
    }
};