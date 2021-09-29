/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        ostringstream out;
        se(root,out);
        return out.str();
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        istringstream in(data);
        return de(in);
    }
    
    void se(TreeNode* root, ostringstream& out){
        if(!root){
            out<<"# ";
            return;
        }
        out<<root->val<<" ";
        se(root->left,out);
        se(root->right,out);
    }
    
    TreeNode* de(istringstream& in){
        
        string val;
        in>>val;
        if(val=="#") return NULL;
        TreeNode* root=new TreeNode(stoi(val));
        root->left=de(in);
        root->right=de(in);
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));