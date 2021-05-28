class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
       
        for(auto num:nums2){
            nums1.push_back(num);
        }
        sort(nums1.begin(),nums1.end());
        for(auto i:nums1)
            cout<<i<<" ";
        cout<<endl;
        int n1=nums1.size();
        double res=0;
        if(n1%2==0){
            res=((double)nums1[n1/2]+(double)nums1[(n1/2)-1])/2;
            //cout<<nums1[n1/2]<<nums1[(n1/2)-1]<<endl;
        }
        else
            res=nums1[n1/2];
        return res;
        
    }
};