class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        vector<vector<int>> res;
       
        for(int i=0;i<n-3;++i){
            if(i>0&&nums[i]==nums[i-1]) continue;
            for(int j=i+1;j<n-2;++j){
                if(j>i+1&&nums[j]==nums[j-1]) continue;
                int k=j+1,p=n-1;
                while(k<p){
                    long sum=(long)nums[i]+nums[j]+nums[k]+nums[p];
                    if(sum==target){
            res.push_back({nums[i],nums[j],nums[k],nums[p]});
                        while(k<p&&nums[k]==nums[k+1]) ++k;
                        while(k<p&&nums[p]==nums[p-1]) --p;
                        ++k;--p;
                    }
                    else if(sum<target) ++k;
                    else --p;
                }
            }
        }
        return res;
    }
};