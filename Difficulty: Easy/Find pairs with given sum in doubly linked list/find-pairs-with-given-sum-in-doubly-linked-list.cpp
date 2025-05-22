// User function Template for C++

/* Doubly linked list node class
class Node
{
public:
    int data;
    Node *next, *prev;
    Node(int val) : data(val), next(NULL), prev(NULL)
    {
    }
};
*/

class Solution {
  public:
    vector<pair<int, int>> findPairsWithGivenSum(Node *head, int target) {
        // code here
        Node* temp=head;
        while(temp->next!=NULL)
        temp=temp->next;
        Node* slow=head;
        Node* fast=temp;
        vector<pair<int,int>>v1;
        if(slow==fast)
        return {};
        while(slow!=fast && slow && fast)
        {
            if(slow->data+fast->data > target)
            fast=fast->prev;
            else if(slow->data+ fast->data < target)
            slow=slow->next;
            else
            {
                v1.push_back({slow->data,fast->data});
                slow=slow->next;
                fast=fast->prev;
            }
            if(slow!=NULL && slow->prev==fast )
            break;
        }
        return v1;
    }
};