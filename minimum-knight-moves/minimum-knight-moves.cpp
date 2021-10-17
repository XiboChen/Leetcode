class Solution {
public:
    int minKnightMoves(int x, int y) {
        x=abs(x);y=abs(y);
        vector<vector<int>> dir{{-2,1},{-1,2},{1,2},{2,1},{2,-1},{1,-2},{-1,-2},{-2,-1}};
        vector<vector<int>> visited(301,vector<int>(301,0));
        visited[0][0]=1;
        queue<pair<int,int>> q;
        q.push({0,0});
        int res=0;
        while(!q.empty()){
            for(int i=q.size();i>0;--i){
                auto t=q.front();q.pop();
                if(t.first==x&&t.second==y) return res;
                for(auto d:dir){
                    int newx=t.first+d[0];
                    int newy=t.second+d[1];
                    if(newx>300||newy>300||visited[abs(newx)][abs(newy)]) 
                        continue;
                    q.push({abs(newx),abs(newy)});
                    visited[abs(newx)][abs(newy)]=1;
                }
            }
            ++res;
        }
        return -1;
    }
};










