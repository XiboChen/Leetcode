class Solution {
public:
    int trap(vector<int>& height) {
        int n=height.size(),res=0,mx=0;
        vector<int> dp(n,0);
        vector<int> dp2(n,0);
        for(int i=0;i<n;++i){
            dp[i]=mx;
            mx=max(mx,height[i]);
        }
        //for(auto i:dp) cout<<i<<" ";
        mx=0;
        for(int i=n-1;i>=0;--i){
            dp2[i]=mx;
            mx=max(mx,height[i]);
           
        }
        // cout<<endl;
        // for(auto i:dp2) cout<<i<<" ";
        // cout<<endl;
        for(int i=0;i<dp.size();++i){
            int sm=min(dp[i],dp2[i]);
            //cout<<sm<<" ";
            if(sm>height[i]){
                res+=sm-height[i];
            }
        }
        return res;
        
        
        
        
//         stack<int> st; //压入坐标
//         int i=0,n=height.size(),res=0;
//         while(i<n){
//             if(st.empty()||height[i]<=height[st.top()]) st.push(i++);
//             else{
//                 int t=st.top();st.pop();
//                 if(st.empty()) continue;
      
//                 res+=(min(height[i],height[st.top()])-height[t])*(i-st.top()-1);
                
//             }
//         }
//         return res;
        
        
        // int n=height.size(),res=0,mx=0;
        // vector<int> dp(n,0);
        // for(int i=0;i<n;++i){
        //     dp[i]=mx;
        //     mx=max(mx,height[i]);
        // }
        //  for(auto i:dp) cout<<i<<"  ";cout<<endl;
        // mx=0;
        // //确定右边最大的时候，已经确定好了左右两边较低的那个高作为短板
        // for(int i=n-1;i>=0;--i){
        //     dp[i]=min(dp[i],mx);
        //     mx=max(mx,height[i]);
        //     if(dp[i]>height[i]) res+=dp[i]-height[i];
        // }
        // for(auto i:dp) cout<<i<<"  ";
        // return res;
    }
};