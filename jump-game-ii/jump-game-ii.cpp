class Solution {
public:
    int jump(vector<int>& nums) {
        int near=0,far=0,steps=0,n=nums.size();
        for(int i=0;i<n;i++){
            if(i>near){  //超过上一个标记最大的far的范围了，所以step++，改变near
                steps++;
                near=far;
            }
            far=max(far,nums[i]+i);
        }
        return steps;
    }
    /*
    Jump as far as possible but lazily.

    [2, 3, 1, 1, 4]
    i    nums[i]   steps   near   far
    -      -         0       0     0
    0      2         0       0     2
    1      3         1       2     4
    2      1         1       2     4
    3      1         2       4     4
    4      4         2       4     8
Time complexity: O(n)
Space complexity: O(1)
    */
};