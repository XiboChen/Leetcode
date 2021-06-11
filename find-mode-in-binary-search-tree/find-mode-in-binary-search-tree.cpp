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
    vector<int> findMode(TreeNode* root) {
        vector<int> res;
        int mx=0;
        unordered_map<int,int> m;
        traversal(root,m,mx);
        for(auto a:m){
            if(a.second==mx)
                res.push_back(a.first);
        }
        return res;
    }
    
    void traversal(TreeNode* root,unordered_map<int,int>& m,int& mx){
        if(!root) return;
        traversal(root->left,m,mx);
        mx=max(mx,++m[root->val]);
        traversal(root->right,m,mx);
    }
};