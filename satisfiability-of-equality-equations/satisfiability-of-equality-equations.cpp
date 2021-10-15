class Solution {
public:
    bool equationsPossible(vector<string>& equations) {
        vector<int> root(26);
        for(int i=0;i<26;++i)
            root[i]=i;
        for(string equ:equations){
            if(equ[1]=='!') continue;
            root[find(root,equ[0]-'a')]=find(root,equ[3]-'a');
        }
        for(string equ:equations){
            if(equ[1]=='=') continue;
            if(find(root,equ[0]-'a')==find(root,equ[3]-'a')) return false;
        }
        return true;
    }
    
    int find(vector<int>& root,int x){
        return root[x]==x?x:find(root,root[x]);
    }
};