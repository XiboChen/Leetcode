class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> res;
        vector<int> in(numCourses,0);
        unordered_map<int,vector<int>> m;
        for(auto pre:prerequisites){
            m[pre[1]].push_back(pre[0]);
            ++in[pre[0]];
        }
        
        queue<int> q;
        for(int i=0;i<numCourses;++i){
            if(in[i]==0) q.push(i);
        }
        while(!q.empty()){
            int t=q.front();q.pop();
            res.push_back(t);
            for(auto i:m[t]){
                --in[i];
                if(in[i]==0) q.push(i);
            }
        }
        if(res.size()!=numCourses) res.clear();
        return res;
    }
};