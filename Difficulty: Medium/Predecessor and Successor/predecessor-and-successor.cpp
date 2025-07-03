/* BST Node
class Node
{
   public:
    int data;
    Node *left;
    Node *right;

    Node(int x){
        data = x;
        left = NULL;
        right = NULL;
    }
}; */

class Solution {
  public:
    vector<Node*> findPreSuc(Node* root, int key) {
        // code here
        Node* succ=NULL;
        Node* pre=NULL;
        Node* curr=root;
        while(curr)
        {
            if(curr->data > key)
            {
                succ=curr;
                curr=curr->left;
            }
            else if(curr->data < key)
            {
                pre=curr;
                curr=curr->right;
            }
            else{
                //matlab ki mereko wo noe hi mil gaya hai ab!!
                Node* curr2=curr;
                if(curr->right)
                {
                    Node* temp=curr->right;
                    succ=temp;
                    while(temp->left)
                    {
                        temp=temp->left;
                        succ=temp;
                    }
                }
                if(curr2->left)
                {
                    curr2=curr2->left;
                    pre=curr2;
                    while(curr2->right)
                    {
                        curr2=curr2->right;
                        pre=curr2;
                    }
                }
                break;
            }
        }
        return {pre,succ};
    }
};