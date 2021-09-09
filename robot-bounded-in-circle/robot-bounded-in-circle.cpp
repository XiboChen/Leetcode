class Solution {
public:
    bool isRobotBounded(string instructions) {
        int idx=0; //0-北，1-东，2-南，3-西
        vector<vector<int>> dirs{{0,1},{1,0},{0,-1},{-1,0}};
        int x=0,y=0;
        for(auto i:instructions){
            if(i=='G') {
                x+=dirs[idx][0];
                y+=dirs[idx][1];
            }
            else if(i=='L'){
                idx=(idx+4-1)%4;
            }
            else
                idx=(idx+1)%4;
        }
        return x==0&&y==0||idx>0;
    }
};