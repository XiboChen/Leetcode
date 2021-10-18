/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>> res;
        map<int,map<int,vector<int>>> m;
        helper(root,m,0,0);
//         for(auto it:m){
//             cout<<"it.first(x): "<<it.first<<" ";
//             for(auto i:it.second){
//                 cout<<"i.first(y): "<<i.first<<" ";
//                 for(auto t:i.second)
//                     cout<<"i.second(vector): "<<t<<" ";
//                 cout<<endl;
//             }
    
//         }
        
        for(auto it:m){
            vector<int> tmp;
            for(auto i:it.second){
                sort(i.second.begin(),i.second.end());
                
                //for(auto a:i.second)
                    //cout<<it.first<<"   ==="<<a<<" ----  ";
                
                tmp.insert(tmp.end(),i.second.begin(),i.second.end());
                
                //for(auto b:tmp) cout<<b<<" ";cout<<endl;
            }
            res.push_back(tmp);
        }
        return res;
    }
    
    void helper(TreeNode* root,map<int,map<int,vector<int>>>& m,int x,int y){
        if(!root) return;
        m[x][y].push_back(root->val);
        helper(root->left,m,x-1,y+1);
        helper(root->right,m,x+1,y+1);
    }
};