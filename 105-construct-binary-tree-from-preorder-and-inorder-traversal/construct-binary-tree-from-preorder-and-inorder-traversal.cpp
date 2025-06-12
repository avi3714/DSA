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
map<int,int>mpp;
void maping(vector<int>&inorder)
{
    int n=inorder.size();
     for(int i=0;i<n;i++)
     mpp[inorder[i]]=i;
}


TreeNode * fn(int start1,int end1,int start2,int end2,vector<int>& preorder, vector<int>& inorder,int &n)
{
    if(start1>end1 || start2>end2)
    return NULL;
  TreeNode* root=new TreeNode(preorder[start1]);
  int index=mpp[preorder[start1]];
  int size=index-start2;
 
  root->left= fn(start1+1,start1+size,index-size,index-1,preorder,inorder,n);

  
  root->right = fn(start1+size+1,end1,index+1,end2,preorder,inorder,n);

  return root;


}
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n=preorder.size();
        maping(inorder);
       TreeNode* root= fn(0,n-1,0,n-1,preorder,inorder,n);
       return root;
        
    }
};