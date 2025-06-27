class Solution {
public:
int f(int i,vector<int>&arr, int n, int k,vector<int>&dp)
{
      if(i==n)
      return 0;
      if(dp[i]!=-1)
      return dp[i];
       int maxi=INT_MIN;
       int len=0;
       int maxans=INT_MIN;
       for(int ind=i;ind<min(i+k,n);ind++)
       { 
         len++;
         maxi=max(maxi,arr[ind]);
         int ans=len*maxi+f(ind+1,arr,n,k,dp);
         maxans=max(maxans,ans);
       }
       return dp[i]= maxans;
}
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n=arr.size();
        vector<int>dp(n,-1);
        return f(0,arr,n,k,dp);
        
    }
};