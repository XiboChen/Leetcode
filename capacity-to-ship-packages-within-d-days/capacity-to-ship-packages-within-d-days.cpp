class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int left=*max_element(weights.begin(),weights.end());
        int right=accumulate(weights.begin(),weights.end(),0);
        while(left<right){
            int m=left+(right-left)/2,day=1,cur=0;
            for(int w:weights){
                cur+=w;
                if(cur>m){
                    cur=w;
                    day++;
                }
            }
            if(day>days) left=m+1;
            else right=m;
        }
        return left;
    }
};