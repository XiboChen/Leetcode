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
    TreeNode* traversal(vector<int>& preorder,int preBegin,int preEnd,
                        vector<int>& inorder,int inBegin,int inEnd){
        if(preBegin==preEnd) return NULL;
        int rootValue=preorder[preBegin];
        TreeNode* root=new TreeNode(rootValue);
        if(preEnd-preBegin==1) return root;
        int split=0;
        for(split=inBegin;split<inEnd;split++){
            if(inorder[split]==rootValue) break;
        }
        int leftpreBegin=preBegin+1,leftpreEnd=preBegin+1+split-inBegin;
        int rightpreBegin=preBegin+1+split-inBegin,rightpreEnd=preEnd;
        int leftinBegin=inBegin,leftinEnd=split;
        int rightinBegin=split+1,rightinEnd=inEnd;
        root->left=traversal(preorder,leftpreBegin,leftpreEnd,inorder,leftinBegin,leftinEnd);
        root->right=traversal(preorder,rightpreBegin,rightpreEnd,inorder,rightinBegin,rightinEnd);
        return root;
    }
    
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if(preorder.size()==0 || inorder.size()==0) return NULL;
        return traversal(preorder,0,preorder.size(),inorder,0,inorder.size());
    }
};