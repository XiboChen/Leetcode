class Solution {
public:
    int mySqrt(int x) {
        if(x<=1) return x;
        int l=0,r=x;
        while(l<r){
            int m=l+(r-l)/2;
            if(x/m>=m) l=m+1;
            else if(x/m<m) r=m;
        }
        return r-1;
    }
};