// User function Template for C++

/*struct Node {
    int data;
    Node *left, *right;
};*/

class Solution {
  public:
  void getinorder(Node* root,vector<int>&inorder)
  {
      if(root==NULL)
      return;
      getinorder(root->left,inorder);
      inorder.push_back(root->data);
      getinorder(root->right,inorder);
      
  }
  void convertintopreorder(Node* root,vector<int>&inorder,int &index)
  {
      if(root==NULL)
      return;
      convertintopreorder(root->left,inorder,index);
      convertintopreorder(root->right,inorder,index);
      root->data=inorder[index++];
  }
    void convertToMaxHeapUtil(Node* root) {
        // Your code goes here
        //inorder of the tree
        vector<int>inorder;
        getinorder(root,inorder);
        int index=0;
        convertintopreorder(root,inorder,index);
        
    }
};
