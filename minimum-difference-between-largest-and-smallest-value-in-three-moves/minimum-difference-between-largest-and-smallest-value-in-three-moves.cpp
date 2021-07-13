class Solution {
public:
    int minDifference(vector<int>& nums) {
        int n=nums.size();
        if(n<=3) return 0;
        sort(nums.begin(),nums.end());
        return min(min(nums[n-1]-nums[3],nums[n-4]-nums[0]),
                   min(nums[n-2]-nums[2],nums[n-3]-nums[1]));
    }
    /*
    1.修改最小的三个值
    2.修改最大的三个值
    3.修改最小的两个值及一个最大的
    4.修改两个最大的值及一个最小的
    */
};