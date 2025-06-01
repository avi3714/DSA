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
int height(TreeNode* node,int &maxi)
{
    if(node==NULL)
    {
        return 0;
    }
    int y=height(node->left,maxi);
    int z=height(node->right,maxi);
    maxi=max(maxi,y+z);
    return 1+max(y,z);
}
    int diameterOfBinaryTree(TreeNode* root) {
        int maxi=0;
    int h= height(root,maxi);
    return maxi;
        
    }
};