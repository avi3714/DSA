class Solution {
  public:
  
class Node{
  public:
  int data;
  int row;
  int col;
  Node(int data,int col,int row)
  {
      this->data=data;
      this->row=row;
      this->col=col;
  }
};
class compare{
  public:
  bool operator()(Node a,Node b){
      return a.data > b.data;
  }
};
    // Function to merge k sorted arrays.
    vector<int> mergeKArrays(vector<vector<int>> arr, int K) {
        // code here
        int n=K;
        vector<int>ans;
        priority_queue<Node,vector<Node>, compare>q;
        for(int i=0;i<n;i++)
        {
            Node r= Node(arr[i][0],0,i);
            q.push(r);
        }
        while(!q.empty())
        {
            Node front=q.top();
            q.pop();
            ans.push_back(front.data);
            int row=front.row;
            int col=front.col;
            if(col+1 < arr[row].size())
            {
                q.push(Node(arr[row][col+1],col+1,row));
            }
        }
        return ans;
        
        
    }
};