class Solution {
  public:
  bool f(int index,vector<int>&arr,int target,vector<vector<int>>&dp)
  {
      if(dp[index][target]!=-1)
      return dp[index][target];
      if(target==0)
      return true;
      if(index==0)
      return arr[0]==target;
      bool nottake=f(index-1,arr,target,dp);
      bool take=false;
      if(arr[index]<=target)
      take=f(index-1,arr,target-arr[index],dp);
      return dp[index][target]= take|nottake;
  }
    bool isSubsetSum(vector<int>& arr, int sum) {
        // code here
        int n=arr.size();
        vector<vector<int>>dp(n,vector<int>(sum+1,-1));
        return f(n-1,arr,sum,dp);
    }
};