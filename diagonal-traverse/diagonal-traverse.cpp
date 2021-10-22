class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        if(mat.empty()||mat[0].empty()) return {};
        int m=mat.size(),n=mat[0].size(),r=0,c=0,k=0;
        vector<int> res(m*n);
        vector<vector<int>> dirs{{-1,1},{1,-1}}; 
        for(int i=0;i<m*n;++i){
            res[i]=mat[r][c];
            r+=dirs[k][0];  
            c+=dirs[k][1];
            if(r>=m){
                r=m-1;
                c+=2;
                k=1-k; //控制转向，dirs[0]/dirs[1]
            }
            if(c>=n){
                c=n-1;
                r+=2;
                k=1-k;
            }
            if(r<0){
                r=0;
                k=1-k;
            }
            if(c<0){
                c=0;
                k=1-k;
            }
        }
        return res;
    }
};