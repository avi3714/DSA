class Solution {
public:
int f(int index,int amount,vector<vector<int>>&dp,vector<int>&coins){
    if(index==0)
    {
        if(amount%coins[index]==0)
        return amount/coins[index];
        else
        return INT_MAX;
    }
    if(amount==0)
    return 0;
    if(dp[index][amount]!=-1)
    return dp[index][amount];
    int take=INT_MAX;
    if(amount-coins[index]>=0)
    {
     take=f(index,amount-coins[index],dp,coins);
     if(take!=INT_MAX)
     take++;

    }
    int nottake=f(index-1,amount,dp,coins);
    return dp[index][amount]=min(take,nottake);
}
    int coinChange(vector<int>& coins, int amount) {
        int n=coins.size();
        vector<vector<int>>dp(n,vector<int>(amount+1,0));
       
        for(int i=0;i<=amount;i++)
        {
            if(i%coins[0]==0)
            dp[0][i]=i/coins[0];
            else
            dp[0][i]=1e9;
        }
        
        for(int i=1;i<n;i++)
        {
            for(int j=1;j<=amount;j++)
            {
               int nottake=dp[i-1][j];
               int take=1e9;
               if(j>=coins[i])
               take=dp[i][j-coins[i]];
               if(take!=1e9)
               take++;
               dp[i][j]=min(take,nottake);
            }
        }
        if(dp[n-1][amount]==1e9)
        return -1;
        return dp[n-1][amount];
        
    }
};