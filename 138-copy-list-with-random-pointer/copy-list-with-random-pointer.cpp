/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        Node* temp=head;
        if(head==0)
        return head;
        while(temp!=NULL)
        {
            Node* newnode=new Node(temp->val);
            newnode->next=temp->next;
            temp->next=newnode;
            temp=newnode->next;
        }
        temp=head;
        while(temp!=NULL)
        {
            if(temp->next!=NULL)
            {
                if(temp->random)
            temp->next->random=temp->random->next;
            else
            temp->next->random=NULL;
            temp=temp->next->next;
            }
            if(temp==NULL)
            break;
        }
        temp=head;
        Node* newnodes=new Node(-1);
    Node* m=newnodes;
        while(temp!=NULL)
        {
            newnodes->next=temp->next;
            temp->next=temp->next->next;
            temp=temp->next;
            newnodes=newnodes->next;
        }
        return m->next;
    }
};