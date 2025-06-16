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
int heightofbinarytree(TreeNode* node,int &d)
{
       if(node==NULL)
       return 0;
       int heightleft=heightofbinarytree(node->left,d);
       int heightright=heightofbinarytree(node->right,d);
       d=max(d,heightleft+heightright);
       return 1+max(heightleft,heightright);
}
    int diameterOfBinaryTree(TreeNode* root) {
        if(root ==NULL)
        return 0;          
        int d=0;
        int height=heightofbinarytree(root,d);
        return d;

        
    }
};