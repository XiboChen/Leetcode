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
    vector<vector<int>> findLeaves(TreeNode* root) {
        vector<vector<int>> res;
        while(root){
            vector<int> leaves;
            root=deleteNode(root,leaves);
            res.push_back(leaves);
        }
        return res;
    }
    
    TreeNode* deleteNode(TreeNode* root, vector<int>& leaves) {
        if(!root)
            return NULL;
        if(!root->left && !root->right){
                leaves.push_back(root->val);
                return NULL;
        }
        root->left=deleteNode(root->left,leaves);
        root->right=deleteNode(root->right,leaves);
        return root;
    }
};