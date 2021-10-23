class Solution {
public:
    vector<int> findBuildings(vector<int>& heights) {
        int max_=0,n=heights.size();
        vector<int> res;
        for(int i=n-1;i>=0;--i){
            if(heights[i]>max_){
                max_=heights[i];
                res.push_back(i);
            }
        }
        reverse(res.begin(),res.end());
        return res;
    }
};