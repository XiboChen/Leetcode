class Solution {
public:
    int minMeetingRooms(vector<vector<int>>& intervals) {
        map<int,int> m;
        for(auto in:intervals){
            ++m[in[0]];
            --m[in[1]];
        }
        int res=0,room=0;
        for(auto it:m){
            room+=it.second;
            res=max(res,room);
        }
        return res;
    }
};