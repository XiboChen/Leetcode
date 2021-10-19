class Solution {
public:
    int findLength(vector<int>& nums1, vector<int>& nums2) {
        int res=0,m=nums1.size(),n=nums2.size();
        for(int t=0;t<m;++t){
            for(int i=t,j=0;i<m&&j<n;){
                int cnt=0;
                while(i<m&&j<n&&nums1[i++]==nums2[j++])
                    ++cnt;
                res=max(res,cnt);
                
            }
        }
        for(int t=0;t<n;++t){
            for(int i=0,j=t;i<m&&j<n;){
                int cnt=0;
                while(i<m&&j<n&&nums1[i++]==nums2[j++])
                    ++cnt;
                res=max(res,cnt);
                
            }
        }
        return res;
    }
};