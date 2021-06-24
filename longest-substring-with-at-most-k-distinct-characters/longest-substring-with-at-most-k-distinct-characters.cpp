class Solution {
public:
    int lengthOfLongestSubstringKDistinct(string s, int k) {
        unordered_map<char,int> m;
        int left=0,n=s.length(),max_len=0;
        for(int i=0;i<s.size();i++){
            m[s[i]]++;
            while(m.size()>k){
                if(--m[s[left]]==0) 
                    m.erase(s[left]);
                left++;
            }
            max_len=max(max_len,i-left+1);
        }
        return max_len;
    }
};