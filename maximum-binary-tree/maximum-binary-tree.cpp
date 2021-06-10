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
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        //这一步不是为了防止最开始为空，而是为了让遍历走到最后一个num再停。
        if(nums.empty()) return NULL; 
     
        int maxValue=0,maxIndex=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]>maxValue){
                maxValue=nums[i];
                maxIndex=i;
            }
        }
        TreeNode* root=new TreeNode(maxValue);
        vector<int> leftnums=vector<int>(nums.begin(),nums.begin()+maxIndex);
        vector<int> rightnums=vector<int>(nums.begin()+maxIndex+1,nums.end());
        root->left=constructMaximumBinaryTree(leftnums);
        root->right=constructMaximumBinaryTree(rightnums);
        return root;
    }
};