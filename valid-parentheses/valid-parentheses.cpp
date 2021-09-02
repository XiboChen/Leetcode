class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        for(int i=0;i<s.size();++i){
            if(s[i]=='('||s[i]=='['||s[i]=='{') st.push(s[i]);
            else{
                if(st.empty()&&(s[i]=='}'||s[i]==')'||s[i]==']'))
                    return false;
                auto t=st.top();
                if(s[i]==')'&&t=='('||s[i]==']'&&t=='['||s[i]=='}'&&t=='{')
                    st.pop();
                else return false;
            }
        }
        return st.empty()?true:false;
        
    }
};

























// class Solution {
// public:
//     bool isValid(string s) {
//         stack<char> st;
//         for(int i=0;i<s.size();++i){
//             if(s[i]=='('||s[i]=='['||s[i]=='{') st.push(s[i]);
//             else{
//                 if(st.empty()) return false;
//                 else{
//                     if(s[i]==')'&&st.top()=='('||s[i]==']'&&st.top()=='['||s[i]=='}'&& st.top()=='{')
//                         st.pop();
//                     else return false;
//                 }
//             }
//         }
//         return st.empty()?true:false;
//     }
// };


// class Solution {
// public:
//     bool isValid(string s) {
//         //这一题和其他括号题不一样，如果是遇到判断左右括号个数必须一样的，可以用+1/-1，这题是必须完全对称。
//         //所以有几个情况：1.遇到左括号就push，判断右括号是不是一对。
//         //               2.遇到右括号了，结果stack里是空的，那肯定是错的，不可能只有一个右括号在最前面。
//         //               3.遇到右括号了，判断是不是和stack的top为一对
//         //               4.其他右括号的可能肯定是错的
//         //                最后看stack是否为空，可能存在多左括号的情况。
//         stack<char> st;
//         for(int i=0;i<s.size();i++){
//             if(s[i]=='(' || s[i]=='[' || s[i]=='{')
//                 st.push(s[i]);
//             else{
//                 if(st.empty())
//                     return false;
//                 if(s[i]==')' && st.top()=='(' || s[i]==']' && st.top()=='[' || s[i]=='}' && st.top()=='{')
//                     st.pop();
//                 //这里一定要写一个else false，因为可能会有其他右括号不匹配的情况，那么就可以直接输出false了。
//                 else
//                     return false;
//             }
//         }
//         if(!st.empty())
//             return false;
//         return true; 
//     }
// };





// // class Solution {
// // public:
// //     bool isValid(string s) {
// //         vector<char> v;
// //         for(int i=0;i<s.size();i++){
// //             v.push_back(s[i]);
// //             if(v.size()>1){
// //                 if(v[v.size()-1]==')'){
// //                     if(v[v.size()-2]=='('){
// //                         v.pop_back();
// //                         v.pop_back();
// //                     }
// //                 }
// //                else if(v[v.size()-1]=='}'){
// //                     if(v[v.size()-2]=='{'){
// //                         v.pop_back();
// //                         v.pop_back();
// //                     }
// //                 }
// //                else if(v[v.size()-1]==']'){
// //                     if(v[v.size()-2]=='['){
// //                         v.pop_back();
// //                         v.pop_back();
// //                     }
// //                 }
// //             }
            
// //         }
        
// //         if(v.empty()){
// //             return true;
// //         }else{
// //             return false;
// //         }
// //     }
// // };