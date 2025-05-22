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
        while(l1!=NULL && l2!=NULL)
        {
            int value;
            if(l1->val+l2->val+carry <10)
            {
                value=l1->val+l2->val+carry;
                carry=0;
            }
            else
            {
                value=l1->val+l2->val+carry-10;
                carry=1;
            }
            ListNode* newnode=new ListNode(value);
            temp->next=newnode;
            temp=temp->next;
            l1=l1->next;
            l2=l2->next;
        }
        if(l1!=NULL)
        {
            temp->next=l1;
            while(l1!=NULL)
            {
            if(l1->val+carry<10)
            {
                l1->val=l1->val+carry;
                carry=0;
            }
            else
            {
                l1->val=l1->val+carry-10;
                carry=1;
            }
            if(l1->next==NULL && carry==1)
            {
                ListNode* newi=new ListNode(1);
                l1->next=newi;
                l1=l1->next;
                carry=0;
            }
            l1=l1->next;
            }

        }
        if(l2!=NULL)
        {
            temp->next=l2;
            while(l2!=NULL)
            {
            if(l2->val+carry<10)
            {
                l2->val=l2->val+carry;
                carry=0;
            }
            else
            {
                l2->val=l2->val+carry-10;
                carry=1;
            }
            if(l2->next==NULL && carry==1)
            {
                ListNode* newi=new ListNode(1);
                l2->next=newi;
                l2=l2->next;
                carry=0;
            }
            l2=l2->next;
            }

        }
        if(carry==1)
        {
             ListNode* newid=new ListNode(1);
             temp->next=newid;
        }
        return temp3->next;

    }
};