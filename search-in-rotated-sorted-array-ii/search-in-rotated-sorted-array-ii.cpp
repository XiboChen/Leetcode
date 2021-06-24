class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int l=0,r=nums.size()-1;
        while(l<=r){
            int m=l+(r-l)/2;
            if(nums[m]==target) return true;
            if(nums[l]==nums[m]) ++l; //不知道谁增序
            else if(nums[m]<=nums[r]){
                //右增序
                if(target>nums[m] && target<=nums[r])
                    l=m+1;
                else r=m-1;
            }
            else{
                //左增序
                if(target<nums[m] && target>=nums[l])
                    r=m-1;
                else l=m+1;
            }
        }
        return false;
    }
};