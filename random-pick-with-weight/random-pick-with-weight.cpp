class Solution {
public:
    Solution(vector<int>& w) {
        num=w;
        for(int i=1;i<num.size();++i){
            num[i]=num[i-1]+w[i];
        }
    }
    
    int pickIndex() {
        int t=rand()%num.back();
        int l=0,r=num.size()-1;
        while(l<r){
            int m=l+(r-l)/2;
            if(num[m]<=t) l=m+1;
            else r=m;
        }
        return r;
    }
private:
    vector<int> num;
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(w);
 * int param_1 = obj->pickIndex();
 */