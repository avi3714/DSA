class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if(head==NULL || head->next==NULL)
        return head;

        ListNode* temp=head;
        int count=1;
        while(temp->next!=NULL)
        {
            temp=temp->next;
            count++;
        }
        int toberotated=count-k%count;
        if(toberotated==count)
        return head;
        toberotated--;
        ListNode* temp1=head;
        while(toberotated--)
        {
            temp1=temp1->next;
        }
        temp->next=head;
        head=temp1->next;
        temp1->next=NULL;
        return head;
    }
};