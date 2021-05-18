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
    bool helper(TreeNode* node, long min,long max){
        if(node==NULL) return true;
        if(node->val<=min || node->val>=max) 
            return false;
        return helper(node->left,min,node->val) && helper(node->right,node->val,max);
    }
    
    bool isValidBST(TreeNode* root) {
        if(helper(root,LONG_MIN,LONG_MAX))
            return true;
        return false;
    }
};