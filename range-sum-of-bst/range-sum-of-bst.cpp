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
    void preorder(TreeNode* node, vector<int>& order){
        if(!node) return;
        order.push_back(node->val);
        preorder(node->left,order);
        preorder(node->right,order);
    }
    
    int rangeSumBST(TreeNode* root, int low, int high) {
        vector<int> order;
        int res=0;
        preorder(root,order);
        for(auto i:order){
            if(i>=low && i<=high){
                res+=i;
            }
        }
        return res;
    }
};