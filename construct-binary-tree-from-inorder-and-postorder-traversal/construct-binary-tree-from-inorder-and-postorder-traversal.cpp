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
    TreeNode* traversal(vector<int>& inorder,vector<int>& postorder){
        if(postorder.size()==0) return NULL;
        int rootValue=postorder[postorder.size()-1];
        TreeNode* root=new TreeNode(rootValue);
        if(postorder.size()==1) return root;
        int splitIndex;
        for(splitIndex=0;splitIndex<inorder.size();splitIndex++){
            if(inorder[splitIndex]==rootValue) break;
        }
        vector<int> leftInorder(inorder.begin(),inorder.begin()+splitIndex);
        vector<int> rightInorder(inorder.begin()+splitIndex+1,inorder.end());
        postorder.resize(postorder.size()-1);
        vector<int> leftPostorder(postorder.begin(),postorder.begin()+leftInorder.size());
        vector<int> rightPostorder(postorder.begin()+leftInorder.size(),postorder.end());
        root->left=traversal(leftInorder,leftPostorder);
        root->right=traversal(rightInorder,rightPostorder);
        return root;
    }
    
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        if(inorder.size()==0||postorder.size()==0) return NULL;
        return traversal(inorder,postorder);
    }
};

/*第一步：如果数组大小为零的话，说明是空节点了。
    if(postorder.size()==0) return NULL;

  第二步：如果不为空，那么取后序数组最后一个元素作为节点元素。
    int rootValue=postorder[postorder.size()-1];
    TreeNode* root=new TreeNode(rootValue);
    if(postorder.size()==1) return root;

  第三步：找到后序数组最后一个元素在中序数组的位置，作为切割点
    int splitIndex;
    for(splitIndex=0;splitIndex<inorder.size();splitIndex++){
        if(inorder[splitIndex]==rootValue) break;
    }

  第四步：切割中序数组，切成中序左数组和中序右数组 （顺序别搞反了，一定是先切中序数组）
    //左闭右开：[0,splitIndex)
    vector<int> leftInorder(inorder.begin(),inorder.begin()+splitIndex);
    //[splitIndex+1,end)
    vector<int> rightInorder(inorder.begin()+splitIndex+1,inorder.end());
    
  第五步：切割后序数组，切成后序左数组和后序右数组
    //舍弃末尾元素（用过了）
    postorder.resize(postorder.size()-1);
    //左闭右开，用inorder的size作为切割点：[0,leftinorder.size)
    vector<int> leftPostorder(postorder.begin(),postorder.begin()+leftInorder.size());
    //[lefinorder.size(),end)
    vector<int> rightPostorder(postorder.begin()+leftInorder.size(),postorder.end());

  第六步：递归处理左区间和右区间
    root->left=traversal(中序左数组，后序左数组);
    root->right=traversal(中序右数组，后续右数组);
  */