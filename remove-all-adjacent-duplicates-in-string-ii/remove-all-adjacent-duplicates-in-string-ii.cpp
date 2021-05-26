class Solution {
public:
    string removeDuplicates(string s, int k) {
        stack<int> st;
        for(int i=0;i<s.size();i++){
            if(i==0 || s[i]!=s[i-1]){
                st.push(1);
            }
            else{
                int tmp=st.top();
                st.pop();
                st.push(++tmp);
                if(st.top()==k){
                    st.pop();
                    s.erase(i-k+1,k);
                    i=i-k;
                }
            }
            
            //cout<<"i:"<<i<<" s[i]: "<<s[i]<<" "<<st.top()<<endl;
        }
        return s;
    }
};