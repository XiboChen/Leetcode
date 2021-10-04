class Solution {
public:
    string minRemoveToMakeValid(string s) {
        stack<int> st;
        for(int i=0;i<s.size();++i){
            if(s[i]=='(') st.push(i);
            else if(s[i]==')'){
                if(st.empty()){
                    //s.erase(s.begin()+i);
                    s[i]='*';
                    continue;
                }
                st.pop();
            }
        }
        while(!st.empty()){
            //s.erase(s.begin()+st.top());
            s[st.top()]='*';
            st.pop();
        }
        string res="";
        for(auto i:s){
            if(i!='*') res+=i;
        }
        return res;
    }
};