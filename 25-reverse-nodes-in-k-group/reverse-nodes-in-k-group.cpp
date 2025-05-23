/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
ListNode* reverse(ListNode* temp)
{
    if(temp==NULL||temp->next==NULL)
    return temp;
    ListNode* prev=NULL;
    ListNode* curr=temp;
    ListNode* front=curr->next;
    while(curr!=NULL)
    {
        curr->next=prev;
        prev=curr;
        curr=front;
        if(front)
        front=front->next;
    }
    return prev;
}
ListNode* findkthnode(ListNode* temp,int k)
{
    k--;
    while(temp!=NULL && k>0)
    {
        temp=temp->next;
        k--;
    }
    return temp;
}
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* previousnode=NULL;
        ListNode* temp=head;
        while(temp!=NULL)
        {
            ListNode* kthnode=findkthnode(temp,k);
            if(kthnode==NULL)
            {
                if(previousnode)
                {
                    previousnode->next=temp;
                }
                break;
            }
            else
            {
                ListNode* nextnode=kthnode->next;
                kthnode->next=NULL;
                kthnode=reverse(temp);
                if(temp==head)
                head=kthnode;
                else
                {
                    previousnode->next=kthnode;
                }
                    previousnode=temp;
                    temp=nextnode;
                }
            }
            return head;
        }

        
    
};