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
        ostringstream s;
        se(root,s);
        return s.str();
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        istringstream in(data);
        return deserialize(in);
    }
    
    void se(TreeNode* root,ostringstream& s){
        if(!root){
            s<<"# ";
            return;
        }
        s<<root->val<<" ";
        se(root->left,s);
        se(root->right,s);
    } 
    
    TreeNode* deserialize(istringstream& in){
        string val;
        in>>val;
        if(val=="#") return NULL;
        TreeNode* root=new TreeNode(stoi(val));
        root->left=deserialize(in);
        root->right=deserialize(in);
        return root;
    }
};




// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));