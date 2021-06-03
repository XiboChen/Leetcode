class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        vector<int> v(10001,0);
        int take=0,skip=0;
        for(auto num:nums)
            v[num]+=num;
        for(int i=0;i<v.size();i++){
            int takei=skip+v[i];
            int skipi=max(take,skip);
            take=takei;skip=skipi;
        }
        return max(take,skip);
    }
};
//        0 1 2 3 4 ...
//     v: 0 0 4 9 4 ...
// takei: 0 0 4 9 8   (new)
// skipi: 0 0 0 4 9   (new)
// take:  0 0 4 9 
// skip:  0 0 0 4

//takei: 拿当前数字
//skipi: 不拿当前数字
//take: 拿上一个数字
//skip：不拿上一个数字