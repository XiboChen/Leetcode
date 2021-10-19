class Solution {
public:
    int countArrangement(int n) {
        vector<int> visited(n+1,0);
        int res=0;
        helper(n,res,1,visited);
        return res;
    }
    
    void helper(int n,int& res,int cur,vector<int>& visited){
        if(cur>n){
            ++res;
            return;
        }
        for(int i=1;i<=n;++i){
            if(visited[i]==0&&(i%cur==0||cur%i==0)){
                visited[i]=1;
                helper(n,res,cur+1,visited);
                visited[i]=0;
            }
        }
    }
};