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
int count=0;
TreeNode* f1;
TreeNode* f2;
TreeNode* f3;
TreeNode* last=new TreeNode(INT_MIN);

void inorder(TreeNode* root)
{
    if(root==NULL)
    return;
    inorder(root->left);
    if(root->val < last->val && count==0)
    {
        f1=last;
        f2=root;
        count++;
    }
    else if(root->val < last->val && count==1)
    {
        f3=root;
        count++;
    }
    last=root;
    inorder(root->right);
}
    void recoverTree(TreeNode* root) {
        f1=NULL;
        f2=NULL;
        f3=NULL;    
        inorder(root);
        if(count==2)
        {
            swap(f1->val,f3->val);
        }
        else
        {
            swap(f1->val,f2->val);
        }
        
    }
};

