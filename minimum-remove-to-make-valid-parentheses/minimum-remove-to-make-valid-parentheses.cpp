class Solution {
public:
    string minRemoveToMakeValid(string s) {
        string res;
        int open=0,close=count(s.begin(),s.end(),')');
        for(auto i:s){
            if(i=='('){
                if(open==close) continue;
                ++open;
            }else if(i==')'){
                --close;
                if(open==0) continue;
                --open;
            }
            res+=i;
        }
        return res;
    }
};