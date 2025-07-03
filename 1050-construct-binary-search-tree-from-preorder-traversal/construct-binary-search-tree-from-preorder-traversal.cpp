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
TreeNode* constructbt(vector<int>&preorder,vector<int>&inorder,int prestart,int preend,int instart, int inend,map<int,int>&mpp)
{
    if(prestart>preend || instart > inend)
    return NULL;
         TreeNode* root=new TreeNode(preorder[prestart]);
         root->left=constructbt(preorder,inorder,prestart+1,prestart+mpp[preorder[prestart]]-instart,instart,mpp[preorder[prestart]]-1,mpp);
         root->right=constructbt(preorder,inorder,prestart+mpp[preorder[prestart]]-instart+1,preend,mpp[preorder[prestart]]+1,inend,mpp);
         return root;
}
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        //so method 1 is to construct inorder and then construct a unique bst.
        vector<int> inorder(preorder);
        sort(inorder.begin(),inorder.end());
        map<int,int>mpp;
        int n=inorder.size();
        for(int i=0;i<n;i++)
        {
            mpp[inorder[i]]=i;
        }
        TreeNode* root=constructbt(preorder,inorder,0,n-1,0,n-1,mpp);
        return root;
        
    }
};