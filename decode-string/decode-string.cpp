class Solution {
public:
    string decodeString(string s) {
        string t="";
        stack<int> s_num;
        stack<string> s_str;
        int cnt=0;
        for(int i=0;i<s.size();++i){
            if(isdigit(s[i])){
                cnt=cnt*10+(s[i]-'0');
            }else if(s[i]=='['){
                s_num.push(cnt);
                s_str.push(t);
                cnt=0;t.clear();
            }else if(s[i]==']'){
                auto n=s_num.top();s_num.pop();
                for(int j=0;j<n;++j)
                    s_str.top()+=t;
                t=s_str.top();s_str.pop();
            }else{
                t+=s[i];
            }
        }
        return s_str.empty()?t:s_str.top();
    }
};