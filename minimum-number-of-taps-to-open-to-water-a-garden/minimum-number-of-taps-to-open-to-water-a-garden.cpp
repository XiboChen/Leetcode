class Solution {
public:
    int minTaps(int n, vector<int>& ranges) {
        int left=0,right=0,res=0;
        vector<int> rightmost(n+1,0);
        for(int i=0;i<=n;++i){
            left=max(0,i-ranges[i]);
            right=min(n,i+ranges[i]);
            rightmost[left]=max(rightmost[left],right);
        }
        int rightm=0,breakp=0;
        for(int i=0;i<n;++i){
            rightm=max(rightm,rightmost[i]);
            if(i==breakp){
                if(rightm<=i)
                    return -1;
                ++res;
                breakp=rightm;
            }
        }
        return res;
    }
};


























