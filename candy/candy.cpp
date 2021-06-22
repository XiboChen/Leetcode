class Solution {
public:
    int candy(vector<int>& ratings) {
        int n=ratings.size(),res=0;
        vector<int> candy(n,1);
        vector<int> candy2(n,1);
        for(int i=1;i<n;i++){
            if(ratings[i]>ratings[i-1])
                candy[i]=candy[i-1]+1;
        }
        for(int i=n-2;i>=0;i--){
            if(ratings[i]>ratings[i+1])
                candy2[i]=candy2[i+1]+1;
        }
        for(int i=0;i<candy.size();i++){
            candy[i]=max(candy[i],candy2[i]);
        }
        for(auto i:candy)
            res+=i;
        return res;
    }
};