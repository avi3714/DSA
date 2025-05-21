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
 ListNode* findmiddle(ListNode* head)
 {
    if(head==NULL||head->next==NULL)
    return head;
    ListNode* slow=head;
    ListNode* fast=head;
    while(fast->next!=NULL && fast->next->next!=NULL)
    {
        fast=fast->next->next;
        slow=slow->next;
    }
    return slow;
 }
 ListNode* mergetwosortedlist(ListNode* left,ListNode* right)
 {
    ListNode* temp=new ListNode(-1);
    ListNode* temp2=temp;
    while(left!=NULL && right!=NULL)
    {
        if(left->val<right->val)
        {
            temp2->next=left;
            left=left->next;
        }
        else
        {
            temp2->next=right;
            right=right->next;
        }
        temp2=temp2->next;
    }
    if(left!=NULL)
    temp2->next=left;
    if(right!=NULL)
    temp2->next=right;
    return temp->next;
 }
    ListNode* sortList(ListNode* head) {
        if(head==NULL||head->next==NULL)
        return head;
        ListNode* middle=findmiddle(head);
        ListNode* right=middle->next;
        middle->next=NULL;
        ListNode* left=head;
        left=sortList(left);
        right=sortList(right);
        return mergetwosortedlist(left,right);  
    }
};