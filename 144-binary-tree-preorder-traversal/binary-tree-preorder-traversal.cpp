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
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int>v;
        if(root==NULL)
        return v;
        while(root)
        {
            if(root->left)
            {
                TreeNode* prev=root->left;
                while(prev->right)
                prev=prev->right;
                prev->right=root->right;
                root->right=root->left;
            }
            v.push_back(root->val);
            root->left=NULL;
            root=root->right;
        }
        return v;
        
    }
};