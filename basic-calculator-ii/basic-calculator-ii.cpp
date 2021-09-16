class Solution {
public:
    int calculate(string s) {
        stack<int> st;
        char op='+';
        long dig=0,res=0,n=s.size();
        for(int i=0;i<s.size();++i){
            if(s[i]>='0'&&s[i]<='9'){
                dig=dig*10+s[i]-'0';
            }
            if((s[i]<'0' && s[i]!=' ')||i==n-1){
                if(op=='+') st.push(dig);
                if(op=='-') st.push(-dig);
                if(op=='*'||op=='/'){
                    int tmp=(op=='*')?st.top()*dig:st.top()/dig;
                    st.pop();
                    st.push(tmp);
                }
                op=s[i];
                dig=0;
            }
        }
        while(!st.empty()){
            res+=st.top();st.pop();
        }
        return res;
    }
};