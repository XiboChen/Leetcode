class Solution {
public:
    int reverse(int x) {
        int sign=x>0?1:-1;
        int dig=0;
        x=abs(x);
        while(x>0){
            if(dig>INT_MAX/10) 
                return 0;
            dig=dig*10+x%10;
            x/=10;
            
        }
        return dig*sign;
    }
};