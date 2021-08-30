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
    int sumRootToLeaf(TreeNode* root) {
        int res=0;
        traverse(root,0,res);
        return res;
    }
    
    void traverse(TreeNode* root, int cur,int& res){
        if(!root) return;
        cur=cur*2+root->val;
        if(!root->left&&!root->right) res+=cur;
        traverse(root->left,cur,res);
        traverse(root->right,cur,res);
    }
};