class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        vector<int> res;
        for(auto num:nums){
            if(num!=val)
                res.push_back(num);
        }
        for(int i=0;i<res.size();i++){
            nums[i]=res[i];
        }
        return res.size();
    }
};