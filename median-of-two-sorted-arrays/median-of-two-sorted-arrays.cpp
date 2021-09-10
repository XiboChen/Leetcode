class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        nums1.insert(nums1.end(),nums2.begin(),nums2.end());
        sort(nums1.begin(),nums1.end());
        double res=0;
        int n=nums1.size();
        return res=(n%2==0)?(double(nums1[n/2])+double(nums1[n/2-1]))/2:(double(nums1[n/2]));
    }
};