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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int>v;
        if(root==NULL)
        return v;
        while(root)
        {
            if(root->left==NULL)
            {
                v.push_back(root->val);
                root=root->right;
            }
            else
            {
                TreeNode* prev=root->left;
                while(prev->right && prev->right !=root)
                {
                    prev=prev->right;
                } 
                if(prev->right==NULL)
                {
                    prev->right=root;
                    root=root->left;
                }
                else
                {
                    v.push_back(root->val);
                    prev->right=NULL;
                    root=root->right;
                }
            }
        }
        return v;
        
    }
};