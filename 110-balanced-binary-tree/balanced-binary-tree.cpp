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
int height(TreeNode* node)
{
    if(node==NULL)
    return 0;
    else 
    return 1+max(height(node->left),height(node->right));
}

bool  checkhight(TreeNode* node)
{
    if(node==NULL)
    return true;
    if(abs(height(node->left)-height(node->right))<=1&&checkhight(node->left)&&checkhight(node->right))
    return true;
    else 
    return false;
}
    bool isBalanced(TreeNode* root) 
    {
        if(root==NULL)
        return true;
        return checkhight(root);
        
    }
};