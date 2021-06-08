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
    void helper(TreeNode* node,int depth,vector<vector<int>>& res){
        if(!node) return;
        if(res.size()==depth){
            res.push_back({});
        }
        res[depth].push_back(node->val);
        if(node->left) helper(node->left,depth+1,res);
        if(node->right) helper(node->right,depth+1,res);
        
    }
    
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> res;
        helper(root,0,res);
        return res;
    }
};