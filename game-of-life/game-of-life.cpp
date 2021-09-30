class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        int m=board.size(),n=board[0].size();
        vector<vector<int>> tmp(board);
        vector<int> dirx{-1,-1,0,1,1,1,0,-1};
        vector<int> diry{0,1,1,1,0,-1,-1,-1};
        for(int i=0;i<m;++i){
            for(int j=0;j<n;++j){
                int cnt=0;
                for(int k=0;k<8;++k){
                    int x=i+dirx[k];
                    int y=j+diry[k];
                    if(x>=0&&y>=0&&x<m&&y<n&&tmp[x][y]==1) cnt++;
                }
                if(board[i][j]==1){
                    if(cnt<2||cnt>3) board[i][j]=0;
                }else{
                    if(cnt==3) board[i][j]=1;
                }
            }
        }
    }
};