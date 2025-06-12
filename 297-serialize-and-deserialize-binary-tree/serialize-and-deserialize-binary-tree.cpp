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
    if (root == NULL) return "#,";  // Correctly encode null nodes
    return to_string(root->val) + "," + serialize(root->left) + serialize(root->right);
}

   TreeNode* buildTree(stringstream& s) {
    string str;
    if (!getline(s, str, ',')) return nullptr;

    if (str.empty() || str == "#") return nullptr;

    TreeNode* node = new TreeNode(stoi(str));
    node->left = buildTree(s);
    node->right = buildTree(s);
    return node;
}


    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
       stringstream s(data);
       return buildTree(s);
    }
  
    
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));