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
    TreeNode* convertBST(TreeNode* root) {
        int sum=0;
        traversal(root,sum);
        return root;
    }
    //因为bst性质，这样加起来反而最左边的最大，所以反过来加
    void traversal(TreeNode* node,int& sum){
        if(!node) return;
        traversal(node->right,sum);
        sum+=node->val;
        node->val=sum;
        traversal(node->left,sum);
    }
};