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
         vector<int>curr(2,0),prev(2,0);
        for(int index=n-1;index>=0;index--)
        {
            int a=-prices[index]+prev[1];
            int b=prev[0];
             curr[0]= max(a,b);

            int c=prices[index]-fee+prev[0];
            int d=prev[1];
             curr[1]= max(c,d);

          prev=curr;
        }
     int fg=curr[0];
     return fg;   
    }
};