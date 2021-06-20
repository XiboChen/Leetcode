class Solution {
public:
    bool isPerfectSquare(int num) {
        if(num==1) return true;
        long l=0,r=num;
        while(l<r){
            long m=l+(r-l)/2,t=m*m;
            if(t==num) return true;
            else if(t<num) l=m+1;
            else r=m;
        }
        return false;
    }
};