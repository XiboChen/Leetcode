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
    void traversal(TreeNode* node, vector<int>& res){
        if(!node) return;
        traversal(node->left,res);
        res.push_back(node->val);
        traversal(node->right,res);
    }
    
    int getMinimumDifference(TreeNode* root) {
        vector<int> res;
        traversal(root,res);
        int diff=INT_MAX;
        for(int i=1;i<res.size();i++){
            diff=min(diff,res[i]-res[i-1]);
        }
        return diff;
    }
};