class Solution {
  public:
  
  int f(int index,int target,vector<vector<int>>&dp,vector<int>&arr)
  {
      if(dp[index][target]!=-1)
      return dp[index][target];
      if(index==0)
      {
          if(target==0 && arr[0]==0)
          return 2;
          if(target==0||arr[0]==target)
          return 1;
          return 0;
      }
      
      int nottake=f(index-1,target,dp,arr);
      int take=0;
      if(arr[index]<=target)
      take=f(index-1,target-arr[index],dp,arr);
      return dp[index][target]=nottake+take;
      
  }
    int perfectSum(vector<int>& arr, int target) {
        // code here
        int n=arr.size();
        vector<vector<int>>dp(n,vector<int>(target+1,-1));
        return f(n-1,target,dp,arr);
    }
};