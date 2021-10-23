class SparseVector {
public:
    
    SparseVector(vector<int> &nums) {
        for(int i=0;i<nums.size();++i){
            if(nums[i]){
                m[i]=nums[i];
            }
        }
    }
    
    // Return the dotProduct of two sparse vectors
    int dotProduct(SparseVector& vec) {
        int res=0;
        for(auto i:vec.m){
            if(m.count(i.first))
                res+=i.second*m[i.first];
        }
        return res;
    }
private:
    unordered_map<int,int> m; //index--num 
};

// Your SparseVector object will be instantiated and called as such:
// SparseVector v1(nums1);
// SparseVector v2(nums2);
// int ans = v1.dotProduct(v2);