/* Tree node structure  used in the program

struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};*/
class NodeInfo{
  public:
  int minNode;
  int maxNode;
  int maxSize;

  NodeInfo(int a,int b,int c)
  {
      this->minNode=a;
      this->maxNode=b;
      this->maxSize=c;
  }
};

class Solution {
  public:

    /*You are required to complete this method */
    // Return the size of the largest sub-tree which is also a BST
    NodeInfo postorder(Node* root)
    {
        if(root==NULL)
        {
            return NodeInfo(INT_MAX,INT_MIN,0);
        }
        NodeInfo lefty=postorder(root->left);
        NodeInfo righty=postorder(root->right);
        if(root->data > lefty.maxNode && root->data < righty.minNode)
        {
            
            return NodeInfo(min(root->data,lefty.minNode),max(root->data,righty.maxNode),1+lefty.maxSize+righty.maxSize);
            
        }
        else
        {
            return NodeInfo(INT_MIN,INT_MAX,max(lefty.maxSize,righty.maxSize));
        }
        
    }
    int largestBst(Node *root) {
        // Your code here
        
       NodeInfo ans=postorder(root);
       return ans.maxSize;
    }
};