class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        unordered_set<int> s(nums.begin(),nums.end());
        int res=1,n=nums.size();
        while(res<=n){
            if(s.count(res)) ++res;
            else break;
        }
        return res;
    }
};