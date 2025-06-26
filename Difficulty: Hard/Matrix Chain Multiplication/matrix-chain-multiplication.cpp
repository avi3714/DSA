class Solution {
  public:
  int f(int i,int j,vector<int> &arr,vector<vector<int>>&dp)
  {
      if(i==j)
      return 0;
      if(dp[i][j]!=-1)
      return dp[i][j];
      int mini=INT_MAX;
      for(int k=i;k<j;k++)
      {
          int ans=f(i,k,arr,dp)+f(k+1,j,arr,dp)+arr[i-1]*arr[k]*arr[j];
          //   A[i-1]*i      A[k-1]*A[k]       A[k]*A[k+1]    A[j-1]*A[j]
          //   A[i-1]*A[k]     A[k]*A[j]
          mini=min(mini,ans);
          
      }
      return dp[i][j]= mini;

  }
    int matrixMultiplication(vector<int> &arr) {
        // code here
        int n=arr.size();
        //matric i has dimenio n i-1*i
        //2 1 3 4
        //  A B C 
        //0 1 2 3
       // cout<<f(1,3,arr)<<endl;
       vector<vector<int>>dp(n,vector<int>(n,-1));
        return f(1,n-1,arr,dp);
    }
};
//f(1,3)
//f(1,1)+f(2,3)+arr[0]*arr[1]*arr[3]