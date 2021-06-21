class Solution {
public:
    int lengthOfLongestSubstringTwoDistinct(string s) {
        unordered_map<char,int> m;
        int left=0,n=s.length(),max_len=0;
        for(int right=0;right<n;right++){
            m[s[right]]=right;
            while(m.size()>2){
                if(m[s[left]]==left)
                    m.erase(s[left]);
                left++;
            }
            max_len=max(max_len,right-left+1);
        }
        return max_len;
    }
};