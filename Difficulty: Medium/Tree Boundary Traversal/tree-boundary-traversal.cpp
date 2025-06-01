/*
// Tree Node
class Node {
  public:
    int data;
    Node* left;
    Node* right;

    // Constructor to initialize a new node
    Node(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }
};
*/

class Solution {
  public:
  bool isleaves(Node* node)
  {
      if(node->left==NULL && node->right==NULL)
      return true;
      else
      return false;
  }
  void addleftboundary(Node* root,vector<int>&res)
  {
      Node* curr=root->left;
      while(curr)
      {
      if(!isleaves(curr))
      res.push_back(curr->data);
      if(curr->left)
      curr=curr->left;
      else
      curr=curr->right;
      }
  }
  void addleaves(Node* root,vector<int>&res)
  {
      if(isleaves(root))
      {
          res.push_back(root->data);
          return;
      }
      if(root->left)
      addleaves(root->left,res);
      if(root->right)
      addleaves(root->right,res);
  }
  void addrightboundary(Node* root,vector<int>&res)
  {
      Node* curr=root->right;
      vector<int>temp;
      while(curr)
      {
          if(!isleaves(curr))
          {
              temp.push_back(curr->data);
          }
          if(curr->right)
          curr=curr->right;
          else
          curr=curr->left;
          
      }
      for(int i=temp.size()-1;i>=0;i--)
      res.push_back(temp[i]);
      
      
  }
    vector<int> boundaryTraversal(Node *root) {
        // code here
        vector<int>res;
        if(!isleaves(root))
        res.push_back(root->data);
        addleftboundary(root,res);
        addleaves(root,res);
        addrightboundary(root,res);
        return res;
    }
};