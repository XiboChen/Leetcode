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
    void helper(TreeNode* node, int value,int& res){
        if(!node) return;
        if(node->val>=value){
            res++;
            value=node->val;
        }
        helper(node->left,value,res);
        helper(node->right,value,res);
    }
    
    int goodNodes(TreeNode* root) {
        int res=0;
        helper(root,INT_MIN,res);
        return res;
    }
};