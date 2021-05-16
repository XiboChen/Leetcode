class Solution {
public:
    //DFS
    bool helper(vector<vector<int>>& graph,vector<bool>& visited,int cur,int pre){
        if(visited[cur]==true) return false;
        visited[cur]=true;
        for(auto j:graph[cur]){
            if(j!=pre){
                if(helper(graph,visited,j,cur)==false) return false; 
            }
        }
        return true;
    }
    
    bool validTree(int n, vector<vector<int>>& edges) {
        vector<vector<int>> graph(n,vector<int>());
        vector<bool> visited(n,false);
        for(auto i:edges){
            graph[i[0]].push_back(i[1]);
            graph[i[1]].push_back(i[0]);
        }
        
        if(!helper(graph,visited,0,-1)) return false;
        
        //有一个单独的点，根本没被遍历到，不连通，不是tree
        for(auto i:visited){
            if(i==false) return false;
        }
        return true;
    }
};