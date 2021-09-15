class Solution {
public:
    bool validPalindrome(string s) {
        int n=s.size(),lo=0,hi=n-1;
        while(lo<hi){
            if(s[lo]!=s[hi]){
                for(int l=lo+1,h=hi;s[l]==s[h];++l,--h){
                    if(l>=h) return true;
                }
                for(int l=lo,h=hi-1;s[l]==s[h];++l,--h){
                    if(l>=h) return true;
                }
                return false;
            }
            --hi;++lo;
        }
        return true;
    }
};