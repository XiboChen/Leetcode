class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> s(nums.begin(),nums.end());
        int res=0;
        for(auto num:nums){
            if(!s.count(num-1)){
                int l=0;
                while(s.count(num++)) ++l;
                res=max(res,l);
            }
            
        }
        return res;
    }
};