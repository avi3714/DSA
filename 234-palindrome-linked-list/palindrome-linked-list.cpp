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
     ListNode* reverse(ListNode* head1)
     {
        ListNode* prev=NULL;
        ListNode* temp=head1;

        while(temp!=NULL)
        {
          ListNode* front=temp->next;
          temp->next=prev;
          prev=temp;
          temp=front;
        }
        return prev;
     }
    bool isPalindrome(ListNode* head) {
        ListNode* slow=head;
        ListNode* fast=head;
        if(head->next==NULL)
        return true;
        while(slow->next!=NULL && fast->next!=NULL&&fast->next->next!=NULL)
        {
            slow=slow->next;
            fast=fast->next->next;
        }
        //reverse the  slow->next
        ListNode* temp2=head;
        ListNode* newhead=reverse(slow->next);
        ListNode* newhead2=newhead;
        while(newhead2!=NULL)
        {
           if(newhead2->val!=temp2->val)
           {
            return false;
           }
           newhead2=newhead2->next;
           temp2=temp2->next;
        }
        return true;

        
    }
};