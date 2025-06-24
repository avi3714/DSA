class Solution {
public:
int f(int index,int buy,vector<int>&prices,int fee,vector<vector<int>>&dp)
{
    if(index>=prices.size())
    return 0;
    if(dp[index][buy]!=-1)
    return dp[index][buy];
    if(buy==0)
    //can buy
    {
        int a=-prices[index]+f(index+1,1,prices,fee,dp);
        int b=f(index+1,0,prices,fee,dp);
        return dp[index][buy]= max(a,b);
    }
    else
    {
        //sell now
        int c=prices[index]-fee+f(index+1,0,prices,fee,dp);
        int d=f(index+1,1,prices,fee,dp);
        return dp[index][buy]= max(c,d);
    }
}
    int maxProfit(vector<int>& prices, int fee) {
        int n=prices.size();
        vector<vector<int>>dp(n+1,vector<int>(2,0));
        for(int index=n-1;index>=0;index--)
        {
            int a=-prices[index]+dp[index+1][1];
            int b=dp[index+1][0];
              dp[index][0]= max(a,b);

            int c=prices[index]-fee+dp[index+1][0];
            int d=dp[index+1][1];
             dp[index][1]= max(c,d);


        }
     int fg=dp[0][0];
     return fg;   
    }
};