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
int totalcount(TreeNode* root)
{
    if(root==NULL)
    return 0;
    return 1+totalcount(root->left)+totalcount(root->right);
}
bool isCBT(TreeNode* root,int index,int totalcount)
{
    if(root==NULL)
    return true;
    if(index>=totalcount)
    return false;
    bool left=isCBT(root->left,2*index+1,totalcount);
    bool right=isCBT(root->right,2*index+2,totalcount);
    return left&&right;
}
    bool isCompleteTree(TreeNode* root) {
        int countnodes=totalcount(root);
        bool ans=isCBT(root,0,countnodes);
        return ans;
        
    }
};