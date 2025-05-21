/*  Node is defined as
  struct Node {
    int data;
    struct Node *next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};*/
class Solution {
  public:
    Node* segregate(Node* head) {
        // code here
        Node* zeronode=new Node(-1);
        Node* zeronodes=zeronode;
        Node* onenode=new Node(-1);
        Node* onenodes=onenode;
        Node* twonode=new Node(-1);
        Node* twonodes=twonode;
        int count0=0,count1=0,count2=0;
        while(head!=NULL)
        {
            if(head->data ==1)
            {count1++;
                onenode->next=head;
                head=head->next;
                onenode=onenode->next;
            }
            else if(head->data ==2)
            {count2++;
                twonode->next=head;
                head=head->next;
                twonode=twonode->next;
            }
            else
            {count0++;
                zeronode->next=head;
                zeronode=zeronode->next;
                head=head->next;
            }
        }
        if(count1>0 )
        {
        zeronode->next=onenodes->next;
        onenode->next=twonodes->next;
        twonode->next=NULL;
        }
        else
        {
            zeronode->next=twonodes->next;
            twonode->next=NULL;
        }
        return zeronodes->next;
        
    }
};
