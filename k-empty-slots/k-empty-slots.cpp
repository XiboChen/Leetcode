class Solution {
public:
    int kEmptySlots(vector<int>& bulbs, int k) {
        int n=bulbs.size(),left=0,right=k+1,res=INT_MAX;
        vector<int> days(n);
        for(int i=0;i<n;++i){
            days[bulbs[i]-1]=i+1;
        }
        for(int i=0;right<n;++i){
            if(days[i]<days[left]||days[i]<=days[right]){
                if(i==right) res=min(res,max(days[left],days[right]));
                left=i;
                right=k+1+i;
            }
        }
        return res==INT_MAX?-1:res;
    }
};