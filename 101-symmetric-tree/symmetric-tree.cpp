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
  bool pre(TreeNode* node1,TreeNode* node2)
  {
   if(node1==NULL||node2==NULL)
   return node1==node2;
   if(node1->val==node2->val && pre(node1->left,node2->right)&&pre(node1->right,node2->left))
   return true;
   else
   return false;

  }
    bool isSymmetric(TreeNode* root) {

        if(root==NULL)
        return true;
        return pre(root->left,root->right);
    }
};