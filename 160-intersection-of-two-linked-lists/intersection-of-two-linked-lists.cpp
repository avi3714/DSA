/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* temp=headA;
        ListNode* temp2=headB;
        int count=0,count2=0;
        while(temp!=NULL)
        {
            count++;
            temp=temp->next;
        }
         while(temp2!=NULL)
        {
            count2++;
            temp2=temp2->next;
        }
        temp=headA;
        temp2=headB;
        while(count>count2)
        {
            temp=temp->next;
            count--;
        }
        while(count2>count)
        {
            temp2=temp2->next;
            count2--;
        }
        while(temp!=NULL)
        {
            if(temp==temp2)
            return temp;
            temp=temp->next;
            temp2=temp2->next;
        }
        return NULL;
    }
};