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
    void helper(TreeNode* node,int& res){
        if(!node) return;
        if(node->left && !node->left->left && !node->left->right){
            res+=node->left->val;
            //return;
        }
        helper(node->left,res);
        helper(node->right,res);
    }
    
    int sumOfLeftLeaves(TreeNode* root) { //main
        int res=0;
        helper(root,res);
        return res;
    }
};