class Solution {
public:
    int compress(vector<char>& chars) {
        int n=chars.size();
        int pos=0;
        for(int i=1;i<=n;++i){
            int cnt=1;
            while(i<n && chars[i]==chars[i-1]){
                ++cnt;++i;
            }
            chars[pos++]=chars[i-1];
            if(cnt==1) continue;
            for(auto i:to_string(cnt))
                chars[pos++]=i;
            
        }
        return pos;
    }
};