class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> res;
        priority_queue<pair<int,int>> q;
        for(int i=0;i<nums.size();i++){
            while(!q.empty()&&q.top().second<=i-k)
                    q.pop();
            q.push(make_pair(nums[i],i));
            if(i>=k-1) res.push_back(q.top().first);
        }
        return res;
    }
};