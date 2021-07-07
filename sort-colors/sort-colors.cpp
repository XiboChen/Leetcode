class Solution {
public:
    void sortColors(vector<int>& nums) {
        bool flag=true;
        for(int i=0;i<nums.size()-1&&flag;i++){
            flag=false;
            for(int j=0;j<nums.size()-1;j++){
                if(nums[j]>nums[j+1]){
                    swap(nums[j],nums[j+1]);
                    flag=true;
                }
            }
        }
        
    }
};