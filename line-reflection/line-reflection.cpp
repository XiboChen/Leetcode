class Solution {
public:
    bool isReflected(vector<vector<int>>& points) {
        int max_=INT_MIN,min_=INT_MAX;
        unordered_map<int,set<int>> m;
        for(auto point:points){
            max_=max(max_,point[0]);
            min_=min(min_,point[0]);
            m[point[0]].insert(point[1]);
        }
        double y=(double)(max_+min_)/2;
        for(auto point:points){
            int t=2*y-point[0];
            if(!m.count(t)||!m[t].count(point[1])) return false;
        }
        
        return true;
    }
};