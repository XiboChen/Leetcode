class Solution {
public:
    int connectSticks(vector<int>& sticks) {
        priority_queue<int,vector<int>,greater<int>> q;
        for(auto i:sticks){
            q.push(i);
        }
        int res=0;
        while(!q.empty()){
            int first=q.top();
            q.pop();
            if(!q.empty()){
                int second=q.top();q.pop();
                int sum=first+second;
                res+=sum;
                q.push(sum);
            }
        }
        return res;
    }
}; 
/*哈夫曼树，用小根堆*/