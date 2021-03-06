class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> res(n,vector<int>(n));
        int up=0,down=n-1,left=0,right=n-1,val=1;
        while(1){
            for(int j=left;j<=right;j++)  //横向最上
                res[up][j]=val++;
            if(++up>down) break;
            for(int i=up;i<=down;i++)  //竖向最右
                res[i][right]=val++;
            if(--right<left) break;
            for(int j=right;j>=left;--j)
                res[down][j]=val++;
            if(--down<up) break;
            for(int i=down;i>=up;--i) 
                res[i][left]=val++;
            if(++left>right) break;
        }
        return res;
    }
};