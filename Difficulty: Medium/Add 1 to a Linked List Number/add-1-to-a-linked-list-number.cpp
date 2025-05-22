/*

struct Node
{
    int data;
    struct Node* next;

    Node(int x){
        data = x;
        next = NULL;
    }
};

*/

class Solution {
  public:
  Node* reverse(Node* head)
  {
      if(head==NULL||head->next==NULL)
      return head;
      Node* prev=NULL;
      Node* curr=head;
      Node* front=head->next;
      while(curr!=NULL)
      {
      front=curr->next;
      curr->next=prev;
      prev=curr;
      curr=front;
      }
      return prev;
  }
    Node* addOne(Node* head) {
        // Your Code here
        Node* temp=reverse(head);
        Node* temp2=temp;
        int carry=1;
        while(temp->next!=NULL)
        {
            if((temp->data)+carry<10)
            {
                temp->data=(temp->data)+1;
                carry=0;
                break;
            }
            else
            {
                temp->data=0;
                temp=temp->next;
            }
        }
        if(carry==1 && temp->next==NULL && temp->data==9)
        {
            Node* temp3=new Node(1);
            temp->next=temp3;
            temp->data=0;
        }
        else if(carry==1)
        {
            temp->data=temp->data+1;
        }
        Node* finalhead=reverse(temp2);
        return finalhead;
        
        // return head of list after adding one
    }
};