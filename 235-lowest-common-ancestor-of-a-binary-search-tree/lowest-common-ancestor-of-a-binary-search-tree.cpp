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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root==NULL)
        return NULL;
        if(root==p || root==q)
        {
            return root;
        }
        TreeNode* lefti=lowestCommonAncestor(root->left,p,q);
        TreeNode* righti=lowestCommonAncestor(root->right,p,q);
        if(righti!=NULL && lefti!=NULL)
        return root;
        if(lefti==NULL)
        return righti;
        if(righti == NULL)
        return lefti;
        return root;

        
    }
};