/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        if(!root) return {};
        unordered_map<TreeNode*,TreeNode*> m;
        unordered_set<TreeNode*> visited;
        vector<int> res;
        findparent(root,m);
        helper(target,k,m,visited,res);
        return res;
    }
    
    void findparent(TreeNode* root,unordered_map<TreeNode*,TreeNode*>& m){
        if(!root) return;
        if(root->left) m[root->left]=root;
        if(root->right) m[root->right]=root;
        findparent(root->left,m);
        findparent(root->right,m);
    }
    
    void helper(TreeNode* root,int k,unordered_map<TreeNode*,TreeNode*>& m,unordered_set<TreeNode*>& visited,vector<int>& res){
        if(!root||visited.count(root)) return;
        visited.insert(root);
        if(k==0){
            res.push_back(root->val);
            return;
        }
        if(root->left) helper(root->left,k-1,m,visited,res);
        if(root->right) helper(root->right,k-1,m,visited,res);
        if(m[root]) helper(m[root],k-1,m,visited,res);
    }
};