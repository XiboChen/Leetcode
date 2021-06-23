class Solution {
public:
    bool checkPossibility(vector<int>& nums) {
        int cnt=1; //一次机会
        for(int i=1;i<nums.size();i++){
            if(nums[i-1]>nums[i]){
                if(cnt==0) return false;
                if(i==1 || nums[i]>=nums[i-2]) nums[i-1]=nums[i];
                else nums[i]=nums[i-1];
                cnt--;
            }
        }
        return true;
    }
};