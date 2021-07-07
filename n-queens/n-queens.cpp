class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> res;
        vector<string> queue(n,string(n,'.'));
        helper(0,res,queue);
        return res;
    }
    
    void helper(int curRow, vector<vector<string>>& res,vector<string>& queue){
        int n=queue.size();
        if(curRow==n){
            res.push_back(queue);
            return;
        }
        for(int i=0;i<n;i++){
            if(isValid(queue,curRow,i)){
                queue[curRow][i]='Q';
                helper(curRow+1,res,queue);
                queue[curRow][i]='.';
            }
        }
    }
    
    bool isValid(vector<string>& queue,int row,int col){
        for(int i=0;i<row;i++){
            if(queue[i][col]=='Q') return false; //因为helper循环时是row不变，col++，                                                所以在这里只需要判断同一col不同row有没有
        }
        for(int i=row-1,j=col-1;i>=0&&j>=0;i--,j--){
            if(queue[i][j]=='Q') return false;
        }
        for(int i=row-1,j=col+1;i>=0&&j<queue.size();i--,j++){
            if(queue[i][j]=='Q') return false;
        }
        return true;
    }
    
    /*
    1.我们先建立一个长度为 nxn 的全是点的数组 queens，然后从第0行开始调用递归。
    2.在递归函数中，首先判断当前行数是否已经为n，是的话，说明所有的皇后都已经成功放置好了，
      只要将 queens 数组加入结果 res 中即可。
    3.否则，遍历该行的所有列的位置，
    4.我们要验证当前位置是否会产生冲突，需要一个子函数来判断，首先验证该列是否有冲突，就遍历之前的所有行，若某一行相同列也有皇后，则冲突返回false；
    5.再验证两个对角线是否冲突，就是一些坐标转换，若都没有冲突，则说明该位置可以放皇后，放了新       皇后之后，再对下一行调用递归即可.
    */
};