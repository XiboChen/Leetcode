class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int n=nums.size(),res=0,d=INT_MAX;
        sort(nums.begin(),nums.end());
        for(int i=0;i<n;++i){
            int j=i+1,k=n-1;
            while(j<k){
                int m=j+(k-j)/2;
                int sum=nums[i]+nums[j]+nums[k];
                if(sum==target) return sum;
                int diff=abs(sum-target);
                if(diff<d){
                    d=diff;
                    res=sum;
                }
                else if(sum>target) --k;
                else ++j;
            }
        }
        return res;
    }
};