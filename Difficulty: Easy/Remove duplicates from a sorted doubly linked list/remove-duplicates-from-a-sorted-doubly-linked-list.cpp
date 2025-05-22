/*
struct Node
{
    int data;
    Node * next;
    Node * prev;
    Node (int x)
    {
        data=x;
        next=NULL;
        prev=NULL;
    }

};
*/

class Solution {
  public:

    Node *removeDuplicates(struct Node *head) {
        // Your code here
        Node* temp=head;
        while(temp!=NULL)
        {
            if(temp->next!=NULL&& temp->data==temp->next->data)
            {
                if(temp==head)
                head=temp->next;
                Node* nexti=temp->next;
                Node* previous=temp->prev;
                if(nexti)
                nexti->prev=previous;
                if(previous)
                previous->next=nexti;
                delete temp;
                temp=nexti;
            }
            else
            temp=temp->next;
            
        }
        return head;
    }
};