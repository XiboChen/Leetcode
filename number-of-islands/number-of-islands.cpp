class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int m=grid.size(),n=grid[0].size(),res=0;
        vector<vector<int>> visited(m,vector<int>(n,0));
        for(int i=0;i<m;++i){
            for(int j=0;j<n;++j){
                res+=grid[i][j]-'0';
                dfs(grid,visited,m,n,i,j);
            }
        }
        return res;
    }
    
    void dfs(vector<vector<char>>& grid,vector<vector<int>>& visited,const int& m,const int& n,int i,int j){
        if(i<0||j<0||i>=m||j>=n||grid[i][j]=='0'||visited[i][j]==1) return;
        visited[i][j]=1;
        grid[i][j]='0';
        dfs(grid,visited,m,n,i+1,j);
        dfs(grid,visited,m,n,i-1,j);
        dfs(grid,visited,m,n,i,j+1);
        dfs(grid,visited,m,n,i,j-1);
    }
};