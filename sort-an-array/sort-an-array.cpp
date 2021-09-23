class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        int n=nums.size();
        vector<int> tmp(n,0);
        mergesort(nums,0,n-1,tmp);
        return nums;
    }
    
    void mergesort(vector<int>& nums,int l,int r,vector<int>& tmp){
        if(l<r){
            int m=l+(r-l)/2;
            mergesort(nums,l,m,tmp);
            mergesort(nums,m+1,r,tmp);
            merge(nums,l,m,r,tmp);
        }
    }
    
    void merge(vector<int>& nums,int l,int m,int r,vector<int>& tmp){
        int ptr=0;
        int ptr1=l,ptr2=m+1;
        while(ptr1<=m&&ptr2<=r){
            if(nums[ptr1]<nums[ptr2])
                tmp[ptr++]=nums[ptr1++];
            else
                tmp[ptr++]=nums[ptr2++];
        }
        while(ptr1<=m)
            tmp[ptr++]=nums[ptr1++];
        while(ptr2<=r)
            tmp[ptr++]=nums[ptr2++];
        for(int i=0;i<r-l+1;++i)
            nums[l+i]=tmp[i];
    }
};

// class Solution {
// public:
//     vector<int> sortArray(vector<int>& nums) {
//         // int n=nums.size();
//         // for(int i=1;i<n;++i){
//         //     int j=i;
//         //     while(j>0&&nums[j-1]>nums[j]){
//         //         swap(nums[j-1],nums[j]);
//         //         --j;
//         //     }
//         // }
//         // return nums;
        
//         // int n=nums.size();
//         // for(int i=0;i<n;++i){
//         //     for(int j=0;j<n-1;++i){
//         //         if(nums[j]>nums[j+1]) swap(nums[j],nums[j+1]); 
//         //     }
//         // }
//         // return nums;
        
//         // int n=nums.size();
//         // for(int i=0;i<n;++i){
//         //     int min_=i;
//         //     for(int j=i+1;j<n;++j){
//         //         if(nums[j]<nums[min_]){
//         //             min_=j;
//         //         }
//         //     }
//         //     if(min_!=i)
//         //         swap(nums[i],nums[min_]);
//         // }
//         // return nums;
//     }
// };