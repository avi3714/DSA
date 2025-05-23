/* Node structure  used in the program

struct Node{
    int data;
    struct Node * next;
    struct Node * bottom;

    Node(int x){
        data = x;
        next = NULL;
        bottom = NULL;
    }

};
*/

class Solution {
  public:
  Node* merge(Node* temporary1,Node* temporary2)
  {
      Node* dummy=new Node(-1);
      Node* dummy2=dummy;
      while(temporary1!=NULL && temporary2!=NULL)
      {
          if(temporary1->data<temporary2->data)
          {
              dummy->bottom=temporary1;
              temporary1=temporary1->bottom;
          }
          else
          {
              dummy->bottom=temporary2;
              temporary2=temporary2->bottom;
          }
              dummy=dummy->bottom;
      }
      if(temporary1!=NULL)
      dummy->bottom=temporary1;
      else
      dummy->bottom=temporary2;
      return dummy2->bottom;
      
  }
    // Function which returns the  root of the flattened linked list.
    Node *flatten(Node *root) {
        // Your code here
        Node* temp=root;
        if(temp==NULL || temp->next==NULL)
        return temp;
        Node* temphead=flatten(temp->next);
        Node* head=merge(root,temphead);
        return head;
        
    }
};