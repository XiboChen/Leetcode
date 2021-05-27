class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<int> st;
        int n=temperatures.size();
        vector<int> res(n,0);
        for(int i=0;i<temperatures.size();i++){
            while(!st.empty()&&temperatures[i]>temperatures[st.top()]){
                int t=st.top();
                st.pop();
                res[t]=i-t;
            }
            st.push(i);
        }
        return res;
    }
};

//brute
//         vector<int> res;
//         int i=0,j=i+1,n=temperatures.size();
//         while(i<n && j<n){
//             if(temperatures[j]>temperatures[i]){
//                 res.push_back(j-i);
//                 i++;
//                 j=i+1;
//             }
//             else{
//                 if(i==n-2&&j==n-1){
//                     res.push_back(0);
//                     continue;
//                 }
//                 j++;        
//             }
            
//         }
//         res.push_back(0);
//         return res;
