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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        
        ListNode* slow=head;
        ListNode* fast=head;
        if(head->next==NULL)
        return NULL;
        while(n--)
        {
          fast=fast->next;
        }
        if(fast==NULL)
        {
            head=head->next;
            return head;
        }
        while(fast->next!=NULL)
        {
            fast=fast->next;
            slow=slow->next;
        }
        ListNode* tempi=slow->next;
        slow->next=slow->next->next;
        delete tempi;
        return head;
    }
};