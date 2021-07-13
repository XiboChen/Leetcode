class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n=nums.size();
        int far=nums[0];
        for(int i=0;i<n;i++){
            if(i>far) break;
            far=max(far,nums[i]+i);
        }
        return far>=n-1;
    }
    /*
    If you can jump to i, then you can jump to at least i + nums[i].
    Always jump as far as you can.
    Keep tracking the farthest index you can jump to.
    Init far = nums[0].
    far = max(far, i + nums[i])
    check far >= n – 1

ex 1 [2,3,1,1,4]
i    nums[i]   i + nums[i]  far
-      -          -          2
0      2          2          2
1      3          4          4
2      1          3          4
3      1          4          4
4      4          8          8

ex 2 [3,2,1,0,4]
i    nums[i]   i + nums[i]  far
-      -          -          3
0      3          3          3
1      2          3          3
2      1          3          3
3      0          3          3 <- can not reach index 4, break
    */
};