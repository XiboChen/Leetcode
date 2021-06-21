class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int m=matrix.size(),n=matrix[0].size();
        vector<int> res;
        int up=0,down=m-1,left=0,right=n-1;
        while(1){
            for(int j=left;j<=right;j++)  //横向最上
                res.push_back(matrix[up][j]);
            if(++up>down) break;
            for(int i=up;i<=down;i++)  //竖向最右
                res.push_back(matrix[i][right]);
            if(--right<left) break;
            for(int j=right;j>=left;--j)
                res.push_back(matrix[down][j]);
            if(--down<up) break;
            for(int i=down;i>=up;--i) 
                res.push_back(matrix[i][left]);
            if(++left>right) break;
        }
        return res;
        
        // int t=0;
        // int r=matrix.size();
        // int b=matrix[0].size();
        // int l=0;
        // int total=r*b;
        // r=r-1;
        // b=b-1;
        // int d=0;
        // int x=0,y=0;
        // vector<int> res;
        // while(res.size()<total-1){
        //     if(d==0){
        //         while(x<b)
        //             res.push_back(matrix[y][x++]);
        //         t++;
        //     }
        //     else if(d==1){
        //         while(y<r)
        //             res.push_back(matrix[y++][x]);
        //         r--;
        //     }
        //     else if(d==2){
        //         while(x>l)
        //             res.push_back(matrix[y][x--]);
        //         b--;
        //     }
        //     else if(d==3){
        //         while(y>t)
        //             res.push_back(matrix[y--][x]);
        //         l++;
        //     }
        //     d=(d+1)%4;
        // }
        // if(res.size()!=total)
        //     res.push_back(matrix[y][x]);
        // return res;
    }
};

