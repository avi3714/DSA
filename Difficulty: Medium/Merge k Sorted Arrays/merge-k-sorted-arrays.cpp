class Solution {
  public:
    // Function to merge k sorted arrays.
    vector<int> mergeKArrays(vector<vector<int>> arr, int K) {
        vector<int>c;
        // code here
        priority_queue<int,vector<int>,greater<int>>pq;
          for(int i=0;i<K;i++)
          {
              for(int j=0;j<K;j++)
              {
                  
               pq.push(arr[j][i]);
              }
              c.push_back(pq.top());
              pq.pop();
          }
          while(!pq.empty())
          {
              c.push_back(pq.top());
              pq.pop();
          }
          return c;
    }
};