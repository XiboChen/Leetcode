class Solution {
public:
    
    unordered_map<int,int> lands;
    
    int largestIsland(vector<vector<int>>& grid) {
        int m=grid.size(),n=grid[0].size();
        int value=2;
        int res=0;
        bool haszero=false;
        for(int i=0;i<m;++i){
            for(int j=0;j<n;++j){
                if(grid[i][j]==1){
                    int cursum=0;
                    dfs(i,j,value,cursum,grid);
                    lands[value]=cursum;
                    value++;
                }
            }
        }
        
        for(int i=0;i<m;++i){
            for(int j=0;j<n;++j){
                if(grid[i][j]==0){
                    haszero=true;
                    res=max(res,helper(grid,i,j));
                }
            }
        }
        return haszero?res:m*n;
    }
    
    void dfs(int x,int y,int val,int& cursum,vector<vector<int>>& grid){
        int m=grid.size(),n=grid[0].size();
        if(x<0||y<0||x>=m|y>=n||grid[x][y]!=1) return;
        if(grid[x][y]==1){
            grid[x][y]=val;
            cursum++;
        }
        dfs(x+1,y,val,cursum,grid);
        dfs(x-1,y,val,cursum,grid);
        dfs(x,y+1,val,cursum,grid);
        dfs(x,y-1,val,cursum,grid);
        return;
    }
    
    int helper(vector<vector<int>>& grid,int x,int y){
        int m=grid.size(),n=grid[0].size();
        int sum=0;
        int flag1=0,flag2=0,flag3=0;
        if((x+1)>=0 && (x+1)<m && y>=0 && y<n){
            if((grid[x+1][y]!=0)){
                sum+=lands[grid[x+1][y]];
                flag1=grid[x+1][y];
            }
        }
        if((x-1)>=0 && (x-1)<m && y>=0 && y<n){
            if(grid[x-1][y]!=0 && grid[x-1][y]!=flag1){
                sum+=lands[grid[x-1][y]];
                flag2=grid[x-1][y];
            }
        }
        if(x>=0 && x<m && y+1>=0 && y+1<n){
            if(grid[x][y+1]!=0 &&(grid[x][y+1]!=flag1) &&(grid[x][y+1]!=flag2)){
                sum+=lands[grid[x][y+1]];
                flag3=grid[x][y+1];
            }
        }
        if(x>=0 && x<m && (y-1)>=0 && (y-1)<n){
            if(grid[x][y-1]!=0 && (grid[x][y-1]!=flag1) && (grid[x][y-1]!=flag2) && (grid[x][y-1]!=flag3)){
                sum+=lands[grid[x][y-1]];
            }
        }
        return sum+1;
    }
};



// class Solution {
// public:
//     int largestIsland(vector<vector<int>>& grid) {
//         int m=grid.size(),n=grid[0].size();
//         int res=0;
//         bool haszero=false;
//         for(int i=0;i<m;++i){
//             for(int j=0;j<n;++j){
//                 if(grid[i][j]==1) continue;
//                 grid[i][j]=1;
//                 vector<vector<bool>> visited(m,vector<bool>(n));
//                 res=max(res,helper(grid,visited,i,j));
//                 if(res==m*n) return res;
//                 grid[i][j]=0;
//                 haszero=true;
//             }
//         }
//         return haszero?res:m*n;
//     }
    
//     int helper(vector<vector<int>>& grid,vector<vector<bool>>& visited,int x,int y){
//         int m=grid.size(),n=grid[0].size();
//         if(x<0||y<0||x>=m|y>=n||grid[x][y]==0||visited[x][y]) return 0;
//         visited[x][y]=true;
//         return 1+helper(grid,visited,x+1,y)+helper(grid,visited,x-1,y)+helper(grid,visited,x,y+1)+helper(grid,visited,x,y-1);
//     }
// };