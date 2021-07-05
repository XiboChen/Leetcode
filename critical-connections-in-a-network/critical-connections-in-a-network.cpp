class Solution {  //O(V+E)  |  O(E)
private:
    vector<vector<int>> edges;
    vector<int> dfn;
    vector<int> low;
    vector<bool> visited;
    vector<vector<int>> res;
    int level;
    
public:   
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        dfn=vector<int>(n,0);
        low=vector<int>(n,0);
        visited=vector<bool>(n,false);
        edges=vector<vector<int>>(n);
        level=0;
        
        for(auto c:connections){
            edges[c[0]].push_back(c[1]);
            edges[c[1]].push_back(c[0]);
        }
        
        tarjan(0,-1);
        return res;
    }
    
    void tarjan(int node, int parent){
        level++;
        dfn[node]=level;
        low[node]=level;
        visited[node]=true;
        
        for(auto child:edges[node]){
            if(child==parent) continue;
            if(!visited[child]){
                tarjan(child,node);
                low[node]=min(low[node],low[child]); //这里用low[child]是因为node是                                     child的父亲，所以能到child的最小的，就可以直接到node
                if(low[child]>dfn[node])  //割边定义，割点是>=
                    res.push_back({node,child});
            }
            else{ //到了访问过了的点，说明是一个闭环，更新low
                //这里用dfn[child]更新是指可以直接从访问过的child这个点直接到达node
                low[node]=min(low[node],dfn[child]); 
            }
        }
    }
    //https://www.cnblogs.com/nullzx/p/7968110.html
};

