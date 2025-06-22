// User function Template for C++

class Solution {
  public:
  int f(int index,int capacity,vector<int>&price,vector<vector<int>>&dp)
  {
      if(dp[index][capacity]!=-1)
      return dp[index][capacity];
      if(capacity==0)
      return 0;
      if(index==0)
      {
          
          return capacity*price[0];
          
      }
      int nottake=f(index-1,capacity,price,dp);
      int take=0;
      if(capacity-(1+index)>=0)
       take=f(index,capacity-(index+1),price,dp)+price[index];
      return dp[index][capacity]= max(take,nottake);
  }
    int cutRod(vector<int> &price) {
        // code here
        int capacity=price.size();
        int n=capacity;
        vector<vector<int>>dp(n,vector<int>(capacity+1,-1));
        return f(n-1,capacity,price,dp);
    }
};