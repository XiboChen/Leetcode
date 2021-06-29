class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m=grid.size(),n=grid[0].size(),res=0,fresh=0;
        vector<vector<int>> dir{{-1,0},{0,1},{1,0},{0,-1}};
        queue<vector<int>> q;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1) fresh++; //fresh orange number++
                else if(grid[i][j]==2) q.push({i,j});
            }
        }
        while(!q.empty()){
            if(fresh==0) break;
            for(int i=q.size();i>0;i--){
                auto t=q.front();q.pop();
                for(auto d:dir){
                    int x=t[0]+d[0],y=t[1]+d[1];
                    if(x<0||x>=m||y<0||y>=n||grid[x][y]!=1) continue;
                    q.push({x,y});
                    grid[x][y]=2;
                    --fresh;
                }
            }
            ++res;
        }
        return fresh>0?-1:res;
    }
};