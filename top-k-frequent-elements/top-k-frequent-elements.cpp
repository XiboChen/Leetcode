class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        auto cmp=[](pair<int,int>& a,pair<int,int>& b){return a.first>b.first;};
        priority_queue<pair<int,int>,vector<pair<int,int>>,decltype(cmp)> q(cmp);
        unordered_map<int,int> m;
        for(auto num:nums) ++m[num];
        for(auto i:m){
            q.push({i.second,i.first});
            if(q.size()>k) q.pop();
        }
        vector<int> res;
        while(!q.empty()){
            res.push_back(q.top().second);
            q.pop();
        }
        return res;
    }
};