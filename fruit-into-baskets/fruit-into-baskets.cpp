class Solution {
public:
    int totalFruit(vector<int>& tree) {
        unordered_map<int,int> m;
        int left=0,n=tree.size(),res=0;
        for(int right=0;right<n;right++){
            m[tree[right]]=right;
            while(m.size()>2){
                if(m[tree[left]]==left) //为了到最后一个位置删除，left再加又是新的开始
                                     //比如ccaabbb,到第二个c才成立删除
                    m.erase(tree[left]);
                left++;
            }
            res=max(res,right-left+1);
        }
        return res;
    }
};