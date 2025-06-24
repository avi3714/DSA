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
        vector<vector<int>>dp(n,vector<int>(2,-1));
     int fg=f(0,0,prices,fee,dp);
     return fg;   
    }
};