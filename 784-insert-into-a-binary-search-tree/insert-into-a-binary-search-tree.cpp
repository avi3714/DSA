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
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        TreeNode* newnode=new TreeNode(val);
        if(root==NULL)
        {
            return newnode;
        }
        TreeNode* init=root;
        while(root)
        {
            if(root->val<val)
            {
                if(root->right==NULL){
                root->right=newnode;
                return init;}
                root=root->right;
            }
            
            else if(root->val>val)
            {
                if(root->left==NULL)
                {
                    root->left=newnode;
                    return init;
                }
                root=root->left;

            }
        }
        return root;
        
    }
};