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
    int Depth(TreeNode* root){
        if(!root) return 0;
        return 1+max(Depth(root->left),Depth(root->right));
    }
    
    bool isBalanced(TreeNode* root) {
        if(!root) return true;
        if(abs(Depth(root->left)-Depth(root->right))>1) return false;
        return isBalanced(root->left) && isBalanced(root->right);
    }
};