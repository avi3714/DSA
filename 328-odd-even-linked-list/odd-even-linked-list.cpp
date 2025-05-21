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
    ListNode* oddEvenList(ListNode* head) {
        if(head==NULL||head->next==NULL)
        return head;
        ListNode* head2=head->next;
        ListNode* p=head;
        ListNode* q=head2;
        while(p->next!=NULL && p->next->next!=NULL)
        {
            p->next=p->next->next;
            p=p->next;
            if(q->next!=NULL && q->next->next !=NULL){
            q->next=q->next->next;
            q=q->next;}
        }
        q->next=NULL;
        p->next=head2;
        return head;
        
    }
};