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
    int findBottomLeftValue(TreeNode* root) {
        queue<TreeNode*> q{{root}};
        vector<vector<int>> res;
        while(!q.empty()){
            vector<int> onelevel;
            for(int i=q.size();i>0;i--){
                TreeNode* t=q.front();q.pop();
                if(t->left) q.push(t->left);
                if(t->right) q.push(t->right);
                onelevel.push_back(t->val);
            }
            res.push_back(onelevel);
        }
        return res[res.size()-1][0];
    }
};