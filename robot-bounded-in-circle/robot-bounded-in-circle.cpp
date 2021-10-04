class Solution {
public:
    bool isRobotBounded(string instructions) {
        int d=0; //0-N,1-E,2-S,3-W
        vector<vector<int>> dir{{0,1},{1,0},{0,-1},{-1,0}};
        vector<int> cur{0,0};
        for(auto ins:instructions){
            if(ins=='G'){
                cur[0]+=dir[d][0];
                cur[1]+=dir[d][1];
            }
            else if(ins=='L'){
                d=(d+4-1)%4;
            }
            else if(ins=='R'){
                d=(d+1)%4;
            }
        }
        return cur[0]==0&&cur[1]==0?true:(d==0?false:true);
    }
};