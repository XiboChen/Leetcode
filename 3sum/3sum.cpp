class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
//         vector<vector<int>> res;
//         sort(nums.begin(),nums.end());
//         int n=nums.size();
//         for(int i=0;i<n-2;++i){
//             if(nums[i]>0) break;
//             if(i>0&&nums[i]==nums[i-1]) continue;
//             int j=i+1,k=n-1;
            
//             while(j<k){
//                 int sum=nums[i]+nums[j]+nums[k];
//                 if(sum==0){
//                     res.push_back({nums[i],nums[j++],nums[k--]});
//                     while(j<k&&nums[j]==nums[j-1]) continue;
//                     while(j<k&&nums[k]==nums[k+1]) continue;
//                 }
//                 else if(sum>0) --k;
//                 else ++j;
//             }
//         }
//         return res;
        vector<vector<int>> res;
        sort(nums.begin(), nums.end());
        if (nums.empty() || nums.back() < 0 || nums.front() > 0) return {};
        for (int k = 0; k < (int)nums.size() - 2; ++k) {
            if (nums[k] > 0) break;
            if (k > 0 && nums[k] == nums[k - 1]) continue;
            int target = 0 - nums[k], i = k + 1, j = (int)nums.size() - 1;
            while (i < j) {
                if (nums[i] + nums[j] == target) {
                    res.push_back({nums[k], nums[i], nums[j]});
                    while (i < j && nums[i] == nums[i + 1]) ++i;
                    while (i < j && nums[j] == nums[j - 1]) --j;
                    ++i; --j;
                } else if (nums[i] + nums[j] < target) ++i;
                else --j;
            }
        }
        return res;
    }
};