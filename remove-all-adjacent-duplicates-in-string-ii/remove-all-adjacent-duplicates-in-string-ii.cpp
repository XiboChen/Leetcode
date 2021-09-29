class Solution {
public:
    string removeDuplicates(string s, int k) {
        stack<int> st;
        for(int i=0;i<s.size();++i){
            if(i==0||s[i]!=s[i-1]) st.push(1);
            else {
                auto t=st.top();
                st.pop();
                st.push(++t);
                if(st.top()==k){
                    st.pop();
                    s.erase(i-k+1,k);
                    i-=k;
                }
            }
        }
        return s;
    }
};