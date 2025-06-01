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
  
    int maxDepth(TreeNode* root) {
        if(root==NULL)
        return 0;
     queue<TreeNode*>q;
     q.push(root);
     int height=0;
     while(!q.empty())
     {
        int r=q.size();
        for(int i=0;i<r;i++)
        {
        TreeNode* frontier=q.front();
        q.pop();
        if(frontier->left)
        q.push(frontier->left);
        if(frontier->right)
        q.push(frontier->right);
        } 
              
        height++;
     }
     return height;
        
    }
};