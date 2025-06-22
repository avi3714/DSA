// User function Template for C++

class Solution {
  public:
  int f(int index,vector<int>& val, vector<int>& wt,int capacity,vector<vector<int>>&dp)
  {
      if(dp[index][capacity]!=-1)
      return dp[index][capacity];
      if(index==0)
      {
          
          return val[0]*(capacity/wt[0]);
          
      }
      int nottake=f(index-1,val,wt,capacity,dp);
      int take=0;
      if(capacity-wt[index]>=0)
      take=f(index,val,wt,capacity-wt[index],dp) + val[index];
      return dp[index][capacity]= max(take,nottake);
  }
  
    int knapSack(vector<int>& val, vector<int>& wt, int capacity) {
        // code here
        int n=val.size();
        vector<vector<int>>dp(n,vector<int>(capacity+1,-1));
        return f(n-1,val,wt,capacity,dp);
    }
};