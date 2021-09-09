class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
       
        sort(intervals.begin(),intervals.end(),[](vector<int>& a,vector<int>& b){
            return a[0]<b[0]||(a[0]==b[0]&&a[1]<b[1]);
        });
         vector<vector<int>> res{intervals[0]};
        
        for(int i=1;i<intervals.size();++i){
            if(intervals[i][0]>res.back()[1]) res.push_back(intervals[i]);
            else{
                res.back()[1]=max(res.back()[1],intervals[i][1]);
            }
        }
        return res;
    }
};