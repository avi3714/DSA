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
TreeNode* helper(TreeNode* node)
{
    if(!node->left)
    return node->right;
    if(!node->right)
    return node->left;
    TreeNode* temp=node->left;
        TreeNode* root2=node->right;
    node=node->right;
    while(node->left)
    {
        node=node->left;
    }
    node->left=temp;
    return root2;
}
    TreeNode* deleteNode(TreeNode* root, int key) {
        //case 1 root is to be deleted
        if(root==NULL)
        return root;
        if(root->val==key)
        {
            return helper(root);
        }
        TreeNode* rut=root;
        while(root)
        {
            if(root->val > key)
            {
                if(root->left && root->left->val==key)
                root->left= helper(root->left);
                else
                root=root->left;
            }
            else
            {
                 if(root->right && root->right->val==key)
                 root->right=helper(root->right);
                 else
                 root=root->right;
            }
        }
        return rut;
    }
};