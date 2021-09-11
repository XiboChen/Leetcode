class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> sett;
        int left=0,n=s.size(),i=0,res=0;
        while(i<n){
            if(!sett.count(s[i])){
                res=max(res,i-left+1);
                sett.insert(s[i]);
                ++i;
            }else{
                sett.erase(s[left++]);
            }
        }
        return res;
    }
};