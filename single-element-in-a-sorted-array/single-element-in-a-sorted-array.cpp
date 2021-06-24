class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int l=0,r=nums.size()-1;
        while(l<r){
            int m=l+(r-l)/2;
            bool halfAreEven=(r-m)%2==0;
            if(nums[m]==nums[m+1]){
                if(halfAreEven){    //①
                    l=m+2;
                }
                else r=m-1;         //②
            }
            else if(nums[m]==nums[m-1]){
                if(halfAreEven){
                    r=m-2;         //③
                }
                else l=m+1;        //④
            }
            else return nums[m];
        }
        return nums[l];
    }
};
    /*
①   0   1   2   3   4    5      6     7   8 
    1   1   4   4   5    5      6     8   8
    l              mid  mid+1  new_l     r
    
②   0   1   2   3   4     5    6    7   8   9   10
    1   1   4   5   5     6    6    8   8   9   9 
    l             new_r  mid  mid+1             r 
    
③   0   1    2      3     4   5   6   7   8 
    1   1    4      5     5   6   6   8   8 
    l      new_r  mid-1  mid              r
    
④   0   1   2    3     4     5   6   7   8   9   10
    1   1   4    4     5     5   6   6   8   9   9 
    l          mid-1  mid  new_l                 r
    
    */