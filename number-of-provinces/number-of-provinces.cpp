// class Solution {
// public:
//     void dfs(vector<vector<int>>& isConnected,int current){
//         for(int i=0;i<isConnected.size();i++){
//             if(isConnected[current][i]==0)
//                 continue;
//             isConnected[current][i]=isConnected[i][current]=0;
//             dfs(isConnected,i);
//         }
//     }
    
//     int findCircleNum(vector<vector<int>>& isConnected) {
//         if(isConnected.empty())
//             return 0;
//         int ans=0;
//         for(int i=0;i<isConnected.size();i++){
//             if(isConnected[i][i]==0)
//                 continue;   //contine means not go to run the next steps, but i+1,and go on.
//             ans++;
//             dfs(isConnected, i);
//         }
//         return ans;
//     }
// };

class Solution {
public:
    int findCircleNum(vector<vector<int>>& M) {
        int n = M.size(), res = n;
        vector<int> root(n);
        for (int i = 0; i < n; ++i) root[i] = i;
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                if (M[i][j] == 1) {
                    int p1 = getRoot(root, i);
                    int p2 = getRoot(root, j);
                    if (p1 != p2) {
                        --res;
                        root[p2] = p1;
                    }
                }
            }   
        }
        return res;
    }
    int getRoot(vector<int>& root, int i) {
        while (i != root[i]) {
            root[i] = root[root[i]];
            i = root[i];
        }
        return i;
    }
};