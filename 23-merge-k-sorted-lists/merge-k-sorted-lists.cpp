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
class compare{
public:
bool operator()(ListNode* a,ListNode*b)
{
    return a->val > b->val;
}
};
    ListNode* mergeKLists(vector<ListNode*>& lists) {
    priority_queue<ListNode*,vector<ListNode*>,compare>q;
    ListNode* head=NULL;
    ListNode* tail=NULL;
    int n=lists.size();
    for(int i=0;i<n;i++)
    {
        if(lists[i])
        q.push(lists[i]);
    }
    while(!q.empty())
    {
        ListNode* front =q.top();
        q.pop();
        if(head==NULL)
        {
            head=front;
            tail=front;
        }
        else
        {
            tail->next=front;
            tail=tail->next;
        }
        if(front->next)
        {
            q.push(front->next);
        }
    }
    return head;

        
    }
};