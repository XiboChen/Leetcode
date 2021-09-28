class Solution {
public:
    string minWindow(string s, string t) {
        int n=s.size(),cnt=0,minlen=INT_MAX,left=0;
        string res="";
        unordered_map<char,int> m;
        for(auto i:t) ++m[i];
        for(int i=0;i<n;++i){
            if(--m[s[i]]>=0) ++cnt;
            while(cnt==t.size()){
                if(minlen>i-left+1){
                    minlen=i-left+1;
                    res=s.substr(left,minlen);
                }
                if(++m[s[left]]>0) --cnt;
                ++left;
            }
        }
        return res;
    }
};