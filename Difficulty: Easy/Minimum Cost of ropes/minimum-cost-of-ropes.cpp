class Solution {
  public:
    int minCost(vector<int>& arr) {
        // code here
        priority_queue<int,vector<int>,greater<int>>pq;
        for(auto it: arr)
        {
            pq.push(it);
        }
        int ans=0;
        while(!pq.empty())
        {
            int a=pq.top();
            pq.pop();
            if(pq.empty())
            break;
            int b=pq.top();
            pq.pop();
            ans+=a+b;
            pq.push(a+b);
        }
        return ans;
    }
};