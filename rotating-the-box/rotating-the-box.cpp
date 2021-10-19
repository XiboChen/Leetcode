class Solution {
public:
    vector<vector<char>> rotateTheBox(vector<vector<char>>& box) {
        int m=box.size(),n=box[0].size();
        for(int i=0;i<m;++i){
            for(int j=n-1;j>=0;--j){
                if(box[i][j]=='#'){
                    if(j==n-1||box[i][j+1]=='*'||box[i][j+1]=='#') continue;
                    box[i][j]='.';
                    for(int k=j;k<n;++k){
                        if(k==n-1||box[i][k+1]=='#'||box[i][k+1]=='*'){
                            box[i][k]='#';
                            break;
                        }
                    }
                }
            }
        }
        
        vector<vector<char>> res(n,vector<char>(m));
        for(int i=m-1;i>=0;--i){
            for(int j=0;j<n;++j){
                res[j][m-i-1]=box[i][j];
            }
        }
        return res;
    }
};