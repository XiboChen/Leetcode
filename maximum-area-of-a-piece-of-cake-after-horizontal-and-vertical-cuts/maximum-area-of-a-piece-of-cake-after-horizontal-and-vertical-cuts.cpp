class Solution {
public:
    int maxArea(int h, int w, vector<int>& horizontalCuts, vector<int>& verticalCuts) {
    
        int mod=1e9+7;
        sort(horizontalCuts.begin(),horizontalCuts.end());
        sort(verticalCuts.begin(),verticalCuts.end());
        
        int maxh=max(horizontalCuts[0],h-horizontalCuts.back());
        int maxv=max(verticalCuts[0],w-verticalCuts.back());
        
        for(int i=1;i<horizontalCuts.size();++i){
            maxh=max(maxh,horizontalCuts[i]-horizontalCuts[i-1]);
        }
        for(int i=1;i<verticalCuts.size();++i){
            maxv=max(maxv,verticalCuts[i]-verticalCuts[i-1]);
        }
        return static_cast<long>(maxh)*maxv%mod;
    }
};