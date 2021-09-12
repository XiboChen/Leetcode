class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        auto cmp=[](pair<int,int>&a ,pair<int,int>& b){
            return a.first*a.first+a.second*a.second<b.first*b.first+b.second*b.second;
        };
        priority_queue<pair<int,int>,vector<pair<int,int>>,decltype(cmp)> q(cmp);
        vector<vector<int>> res;
        for(int i=0;i<points.size();++i){
            q.push({points[i][0],points[i][1]});
            if(q.size()>k){
                q.pop();
            }
        }
        while(!q.empty()){
            auto t=q.top();q.pop();
            res.push_back({t.first,t.second});
        }
        return res;
    }
};