class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        int m=board.size(),n=board[0].size();
        vector<vector<bool>> visited(m,vector<bool>(n,false));
        for(int i=0;i<m;++i){
            for(int j=0;j<n;++j){
                if(dfs(board,visited,word,i,j,0)) return true;
            }
        }
        return false;
    }
    
    bool dfs(vector<vector<char>>& board,vector<vector<bool>>& visited, string& word,int i,int j,int idx){
        int m=board.size(),n=board[0].size();
        if(idx>=word.size()) return true;
        if(i<0||j<0||i>=m||j>=n||visited[i][j]==true||board[i][j]!=word[idx]) return false;
        visited[i][j]=true;
        bool res=dfs(board,visited,word,i+1,j,idx+1)||dfs(board,visited,word,i-1,j,idx+1)||dfs(board,visited,word,i,j+1,idx+1)||dfs(board,visited,word,i,j-1,idx+1);
        visited[i][j]=false;
        return res;
    }
};