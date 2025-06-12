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
TreeNode* fn(int start1,int end1,int start2,int end2,vector<int>& inorder, vector<int>& postorder,map<int,int>&mpp,int &n)
{
    if(start1>end1 || start2>end2)
    return NULL;
    TreeNode* root=new TreeNode(postorder[end1]);
    int index=mpp[postorder[end1]];
    int size=end2-index;
    root->right=fn(end1-size,end1-1,end2-size+1,end2,inorder,postorder,mpp,n);
    root->left=fn(start1,end1-size-1,start2,index-1,inorder,postorder,mpp,n);
    return root;
}
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        map<int,int>mpp;
        int n=postorder.size();
        for(int i=0;i<n;i++)
        {
            mpp[inorder[i]]=i;
        }
        return fn(0,n-1,0,n-1,inorder,postorder,mpp,n);

        
    }
};