class Solution {
public:
class Node{
 public:
 int row;
 int val;
 int col;
 Node(int row,int col,int val)
 {
    this->row=row;
    this->col=col;
    this->val=val;
 }
};
class compare{
    public:
    bool operator()(Node* a,Node*b){
       return a->val > b->val;
    }
};
    vector<int> smallestRange(vector<vector<int>>& nums) {
        int n=nums.size();
        priority_queue<Node*,vector<Node*>,compare>q;
        int mini=INT_MAX;
        int maxi=INT_MIN;
        for(int i=0;i<n;i++)
        {
            Node* newnode=new Node(i,0,nums[i][0]);
            q.push(newnode);
            maxi=max(nums[i][0],maxi);
        }
        mini=q.top()->val;
        int ans=maxi-mini;
        int minimum=mini,maximum=maxi;
        while(true)
        {
            Node* frontier=q.top();
            mini=frontier->val;
            q.pop();
            if(maxi-mini<ans)
            {
                ans=maxi-mini;
                minimum=mini;
                maximum=maxi;
            }
            int row=frontier->row;
            int col=frontier->col;
            if(col+1<nums[row].size())
            {
                Node* next=new Node(row,col+1,nums[row][col+1]);
                maxi=max(maxi,nums[row][col+1]);
                q.push(next);
            }
            else
            break;
           
        }
        return {minimum,maximum};


        
    }
};