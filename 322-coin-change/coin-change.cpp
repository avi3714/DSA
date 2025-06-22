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
        vector<vector<int>>dp(n,vector<int>(amount+1,-1));
        int ans=f(n-1,amount,dp,coins);
        if(ans==INT_MAX)
        return -1;
        return ans;
        
    }
};