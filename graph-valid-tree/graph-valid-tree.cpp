class Solution {
public:
    bool helper(vector<vector<int>>& graph, vector<bool>& visited,int cur,int pre){
        if(visited[cur]==true) return false;
        visited[cur]=true;
        for(int i=0;i<graph[cur].size();i++){
            if(graph[cur][i]!=pre){
                if(!helper(graph,visited,graph[cur][i],cur))
                    return false;
            }
        }
        return true;
    }
    
    bool validTree(int n, vector<vector<int>>& edges) {
        vector<vector<int>> graph(n,vector<int>());
        for(auto i:edges){
            graph[i[0]].push_back(i[1]);
            graph[i[1]].push_back(i[0]);
        }
        vector<bool> visited(n,false);
        if(!helper(graph,visited,0,-1))
            return false;
        for(int i=0;i<visited.size();i++){
            if(visited[i]==false) return false;
        }
        return true;
    }
};