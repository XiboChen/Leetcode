class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {//(main)
        int res=0;
        for(int i=0;i<matrix.size();i++){//遍历每一个点（作为每个方形左上角）
            vector<int> v(matrix[0].size(),0);
            for(int j=i;j<matrix.size();j++){
                for(int k=0;k<matrix[j].size();k++){//这个for只是为了给v不断地赋值
                    if(matrix[j][k]=='1') v[k]++;//v一直在累加
                }
                res=max(res,getSquareArea(v,j-i+1));//j-i+1传值为了确认竖边的长度，
                                                    //而v代表横边
            }
        }
        return res;
    }
    
    int getSquareArea(vector<int>& v,int k){
        if(v.size()<k) return 0;
        int cnt=0;
        for(int i=0;i<v.size();i++){
            if(v[i]!=k) cnt=0; //除非有连续k个是都为1，正好又是方形，最后才可能cnt==k
            else cnt++;
            if(cnt==k) return k*k;
        }
        return 0;
    }
};