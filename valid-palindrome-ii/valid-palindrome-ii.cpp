class Solution {
public:
    bool validPalindrome(string s) {
        int n=s.size(),i=0,j=n-1;
        while(i<j){
            if(s[i]!=s[j]) return isv(s,i+1,j)||isv(s,i,j-1);
            ++i;--j;
        }
        return true;
    }
    
    bool isv(string s,int l,int r){
        while(l<r){
            if(s[l]!=s[r]) return false;
            ++l,--r;
        }
        return true;
    }
};