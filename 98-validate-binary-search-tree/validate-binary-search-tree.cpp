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
bool isanswer(TreeNode* root, long long low,long long high)
{
    if(root==NULL)
    return true;
    if(root->val>=low&& root->val <=high && isanswer(root->left,low,(long long)root->val-1) && isanswer(root->right,(long long)root->val+1,high))
    return true;
    else
    return false;
}
    bool isValidBST(TreeNode* root) {
     long long low=LLONG_MIN;
     long long high=LLONG_MAX;
        return isanswer(root,low,high);

        
    }
};