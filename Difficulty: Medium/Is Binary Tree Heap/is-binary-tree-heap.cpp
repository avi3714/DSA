// Structure of node
/*class Node {
   public:
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};*/

class Solution {
  public:
  int countnode(Node * root)
  {
      if(root==NULL)
      return 0;
      return 1+countnode(root->left)+countnode(root->right);
  }
  bool isCBT(Node* root,int index,int count)
  {
      if(root==NULL)
      return true;
      if(index>=count)
      return false;
      bool left=isCBT(root->left,2*index+1,count);
      bool right=isCBT(root->right,2*index+2,count);
      return left&&right;
  }
  bool ismaxheap(Node* node)
  {
      if(node==NULL)
      return true;
      
      
      
      
       if(!node->left && !node->right)
      return true;
      else if(!node->right )
      {
           if(node->left->data  <=  node->data )
          return ismaxheap(node->left);
          else
          return false;
      }
      else if(!node->left && node->right)
      return false;
      else{
          if(node->left->data<=node->data && node->right->data <= node->data)
          return ismaxheap(node->left)&&ismaxheap(node->right);
          else
          return false;
          
      }
      
  }
    bool isHeap(Node* tree) {
        // code here
        int count=countnode(tree);
        bool cbt= isCBT(tree,0,count);
        bool maxheap=ismaxheap(tree);
        return cbt&&maxheap;
        
    }
};