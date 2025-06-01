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
    {
        int lefty=height(node->left);
        int righty=height(node->right);
        if(lefty==-1||righty==-1)
        return -1;
        else if(abs(lefty-righty)>1)
        return -1;
        else 
        return 1+max(lefty,righty);
    }
    
}
    bool isBalanced(TreeNode* root) 
    {
        if(root==NULL)
        return true;
        int re=height(root);
        if(re==-1)
        return false;
        else 
        return true;
        //return (re==-1);
        
    }
};