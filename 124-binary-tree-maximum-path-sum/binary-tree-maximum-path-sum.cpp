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
       int maximumpathsum(TreeNode* node,int &maxi)
       {
          if(node==NULL)
          return 0;
          int leftsum=max(0,maximumpathsum(node->left,maxi));
          int rightsum=max(0,maximumpathsum(node->right,maxi));
          maxi=max(node->val+leftsum+rightsum,maxi);
          return node->val+max(leftsum,rightsum);
       }
    int maxPathSum(TreeNode* root) {
        int maxi=root->val;
        maximumpathsum(root,maxi);
        return maxi;
    }
};