class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int> q;
        int res=0;
        for(auto num:nums){
            q.push(num);
        }
        for(int i=0;i<k-1;i++){
            q.pop();
        }
        res=q.top();
        return res;
    }
};