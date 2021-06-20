class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int slow=0;
        for(int fast=0;fast<nums.size();fast++){
            if(nums[fast]!=nums[slow])
                nums[++slow]=nums[fast];
        }
        return nums.empty()?0:slow+1;
    }
};