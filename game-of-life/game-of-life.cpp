class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        int m=board.size(),n=board[0].size();
        vector<int> dx{-1,-1,0,1,1,1,0,-1};
        vector<int> dy{0,1,1,1,0,-1,-1,-1};
        for(int i=0;i<m;++i){
            for(int j=0;j<n;++j){
                int cnt=0;
                for(int k=0;k<8;++k){
                    int x=i+dx[k],y=j+dy[k];
                    if(x>=0&&x<m && y>=0&&y<n && (board[x][y]==1||board[x][y]==2))
                        ++cnt;
                }
                if(board[i][j]&&(cnt<2 ||cnt>3)) board[i][j]=2;
                else if(!board[i][j]&&cnt==3) board[i][j]=3;
            }
        }
        for(int i=0;i<m;++i){
            for(int j=0;j<n;++j){
                board[i][j]%=2;
            }
        }
    }
    /*
    1. 如果活细胞周围八个位置的活细胞数少于两个，则该位置活细胞死亡
    2. 如果活细胞周围八个位置有两个或三个活细胞，则该位置活细胞仍然存活
    3. 如果活细胞周围八个位置有超过三个活细胞，则该位置活细胞死亡
    4. 如果死细胞周围正好有三个活细胞，则该位置死细胞复活
    
    1. 1  周围只有一个1或者没有1    变成0   状态2
    2. 1  周围有2个或3个1          变成1   状态1
    3. 1  周围有三个以上1          变成0   状态2
    4. 0  周围有三个1              变成1   状态3
    
    状态0：死 -> 死
    状态1：活 -> 活
    状态2：活 -> 死
    状态3：死 -> 活
    如果小于两个活细胞或者大于三个活细胞，而且当前位置是活细胞的话，标记状态2
    如果正好有三个活细胞且当前是死细胞的话，标记状态3
    最后对2取余，状态0和2变成死，状态1和3变成活。
    */
};