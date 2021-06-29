class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n=grid.size(),res=0;
        if(grid[0][0]==1) return -1;
        vector<vector<int>> dir={{-1,0},{-1,1},{0,1},{1,1},{1,0},{1,-1},{0,-1},{-1,-1}};
        queue<vector<int>> q;
        q.push({0,0});
        while(!q.empty()){
            ++res;
            for(int i=q.size();i>0;i--){
                auto t=q.front();q.pop();
                if(t[0]==n-1 && t[1]==n-1) return res;  //返回结果
                for(auto d:dir){
                    int x=t[0]+d[0],y=t[1]+d[1];
                    if(x<0||x>=n||y<0||y>=n||grid[x][y]==1) continue;
                    q.push({x,y});
                    grid[x][y]=1;
                }
            }
        }
        return -1;
    }
};