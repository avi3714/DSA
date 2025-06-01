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
  int finddepth(TreeNode* node)
  {
    if(node==NULL)
    return 0;
    
    return max(1+finddepth(node->left),(1+finddepth(node->right)));
    
  }
    int maxDepth(TreeNode* root) {
     return finddepth(root);
        
    }
};