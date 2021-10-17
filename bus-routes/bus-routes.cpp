class Solution {
public:
    int numBusesToDestination(vector<vector<int>>& routes, int source, int target) {
        int res=0;
        if(source==target) return 0;
        unordered_map<int,vector<int>> m;
        unordered_set<int> visited;
        queue<int> q{{source}};
        
        for(int i=0;i<routes.size();++i){
            for(auto j:routes[i]){
                m[j].push_back(i);
            }
        }
        
        while(!q.empty()){
            ++res;
            for(int i=q.size();i>0;--i){
                auto t=q.front();q.pop();
                for(int bus:m[t]){
                    if(visited.count(bus)) continue;
                    visited.insert(bus);
                    for(int tmp:routes[bus]){
                        if(tmp==target) return res;
                        q.push(tmp);
                    }
                }
            }
        }
        return -1;
    }
};