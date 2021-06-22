class Solution {
public:
    
    
    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
        unordered_map<int,int> m; //a+b的值---次数
        for(auto a:nums1){
            for(auto b:nums2){
                m[a+b]++;
            }
        }
        int cnt=0;
        for(auto c:nums3){
            for(auto d:nums4){
                if(m.count(0-(c+d)))
                    cnt+=m[0-(c+d)];
            }
        }
        return cnt;
    }
};