class Solution {
public:
    int calculate(string s) {
        stack<int> st;
        long cur=0,n=s.size(),res=0;
        char operation='+';
        for(int i=0;i<n;i++){
            
            if(isdigit(s[i])){
                cur=cur*10+s[i]-'0';
            }
            if(!isdigit(s[i])&&s[i]!=' ' || i==n-1){
                if(operation=='+')
                    st.push(cur);
                if(operation=='-')
                    st.push(-cur);
                if(operation=='*'||operation=='/'){
                    int t=(operation=='*')?cur*st.top():st.top()/cur;
                    st.pop();
                    st.push(t);
                }
                operation=s[i];
                cur=0;
            }
        }
        while(!st.empty()){
            res+=st.top();
            st.pop();
        }
        return res;
    }
};