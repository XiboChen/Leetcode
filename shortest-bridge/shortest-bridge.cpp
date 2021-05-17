class Solution {
public:
    void helper(vector<vector<int>>& grid,int x,int y,int m,int n,queue<int>& q){
        if(x<0||y<0||x>=m||y>=n||grid[x][y]==0||grid[x][y]==2) return;
        grid[x][y]=2;
        q.push(x*n+y); //把遍历到的每个点存入queue,用来遍历上下左右每个点
        //此时queue里就存了当前这一片1的所有坐标
        helper(grid,x+1,y,m,n,q);
        helper(grid,x-1,y,m,n,q);
        helper(grid,x,y+1,m,n,q);
        helper(grid,x,y-1,m,n,q);
    }
    
    int shortestBridge(vector<vector<int>>& grid) {
        int m=grid.size(),n=grid[0].size(),res=0;
        int startX=-1,startY=-1;
        vector<int> corX={-1,0,1,0},corY={0,1,0,-1};
        queue<int> q;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==0) continue;
                startX=i;startY=j;
                break;
            }
            
        }
        helper(grid,startX,startY,m,n,q);// 遍历开始点的所有邻居，把他们变为2
        while(!q.empty()){
            for(int i=q.size()-1;i>=0;i--){
                int t=q.front();q.pop();
                for(int k=0;k<4;k++){
                    int x=t/n+corX[k],y=t%n+corY[k];
                    if(x<0||y<0||x>=m||y>=n||grid[x][y]==2) continue;
                    if(grid[x][y]==1) return res;
                    grid[x][y]=2;
                    q.push(x*n+y);
                }
            }
            ++res;
        }
        return res;
    }
};