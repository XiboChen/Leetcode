class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> s(nums.begin(),nums.end());
        int res=0;
        for(auto num:nums){
            if(!s.count(num)) continue;
            s.erase(num);
            int pre=num-1, nxt=num+1;
            while(s.count(pre)){
                s.erase(pre);
                --pre;
            }
            while(s.count(nxt)){
                s.erase(nxt);
                ++nxt;
            }
            res=max(res,nxt-pre-1);
        }
        return res;
    }
};