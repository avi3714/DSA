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
    ListNode* rotateRight(ListNode* head, int k) {
        if(head==NULL || head->next==NULL)
        return head;

        ListNode* temp=head;
          ListNode* temp1=head;

        int count=1;
        while(temp->next!=NULL)
        {
            temp=temp->next;
            count++;
        }
        temp->next=head;
        k=k%count;
        int toberotated=count-k-1;  
        while(toberotated--)
        {
            temp1=temp1->next;
        }
        head=temp1->next;
        temp1->next=NULL;
        
        return head;
    }
};