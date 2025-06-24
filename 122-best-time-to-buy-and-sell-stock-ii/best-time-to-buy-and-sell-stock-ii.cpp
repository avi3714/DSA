class Solution {
public:
int f(int index,int buy,vector<int>&prices,vector<vector<int>>&dp)
{
    if(index>=(prices.size()))
    {
        return 0;
    }
    if(dp[index][buy]!=-1)
    return dp[index][buy];
    if(buy==1)
    {
        int a=prices[index]+f(index+1,0,prices,dp);
        int b=f(index+1,1,prices,dp);
        return dp[index][buy]=max(a,b);
    }
    else
    {
        int c=f(index+1,1,prices,dp)-prices[index];
        int d=f(index+1,0,prices,dp);
        return dp[index][buy]=max(c,d);
    }
}
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        int index=prices.size();
        vector<vector<int>>dp(index,vector<int>(2,-1));
        return f(0,0,prices,dp);
        
    }
};