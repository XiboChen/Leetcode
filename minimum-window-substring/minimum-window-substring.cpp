class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char,int> m;
        for(auto c:t){
            m[c]++;
        }
        int cnt=0,left=0,minLen=INT_MAX;
        string res="";
        for(int i=0;i<s.size();i++){
            m[s[i]]--;
            if(m[s[i]]>=0) cnt++;
            while(cnt==t.size()){
                if(minLen>i-left+1){
                    minLen=i-left+1;
                    res=s.substr(left,minLen);
                }
                if(++m[s[left]]>0) cnt--;
                left++;
            }
        }
        return res;
    }
};