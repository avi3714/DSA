class Solution {
  public:
    int countPartitions(vector<int>& arr, int d) {
        // Code here
        int n=arr.size();
        int total=accumulate(arr.begin(),arr.end(),0);
        if((total+d)%2==1)
        return 0;
        int target=(total+d)/2;
        //return target;
        vector<vector<int>>dp(n,vector<int>(target+1,0));
        for(int i=0;i<n;i++)
        dp[i][0]=1;
        if(arr[0]==0)
        dp[0][0]++;
        if(arr[0]<=target && arr[0]!=0)
        dp[0][arr[0]]=1;
        for(int i=1;i<n;i++)
        {
            for(int targ=0;targ<=target;targ++)
            {
                int nottake=dp[i-1][targ];
                int take=0;
                if(targ>=arr[i])
                {
                    take=dp[i-1][targ-arr[i]];
                }
                dp[i][targ]=take+nottake;
            }
        }
        return dp[n-1][target];
    }
};