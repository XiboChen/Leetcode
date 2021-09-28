class Solution {
public:
    int countArrangement(int n) {
        int res=0;
        vector<bool> visited(n+1,false);
        helper(n,visited,res,1);
        return res;
    }
    
    void helper(int n,vector<bool>& visited,int& res,int pos){
        if(pos>n){
            ++res;
            return;
        }
        for(int i=1;i<=n;++i){
            if(visited[i]==false&&(i%pos==0||pos%i==0)){
                visited[i]=true;
                helper(n,visited,res,pos+1);
                visited[i]=false;
            }
        }
    }
};