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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int carry=0;
        ListNode* temp=new ListNode(-1);
        ListNode* temp3=temp;
        while(l1!=NULL || l2!=NULL)
        {
            int value=carry;
            if(l1)
            value+=l1->val;
            if(l2)
            value+=l2->val;
            if(value <10)
            {
                carry=0;
            }
            else
            {
                value=value-10;
                carry=1;
            }
            ListNode* newnode=new ListNode(value);
            temp->next=newnode;
            temp=temp->next;
            if(l1)
            l1=l1->next;
            if(l2)
            l2=l2->next;
        }
   
        if(carry==1)
        {
             ListNode* newid=new ListNode(1);
             temp->next=newid;
        }
        return temp3->next;

    }
};