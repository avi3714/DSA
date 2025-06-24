class Solution {
public:
int f(int index,int buy,vector<int>&prices,vector<vector<int>>&dp)
{
    if(index>=prices.size())
    return 0;
    //not bought
    if(dp[index][buy]!=-1)
    return dp[index][buy];
    if(buy==0)
    {
        //buy it
        int a=-prices[index]+f(index+1,1,prices,dp);
        //dont buy it
        int b=f(index+1,0,prices,dp);
        return dp[index][buy]= max(a,b);
    }
    else
    {
        //bought
        //sell it
        int c=prices[index]+f(index+2,0,prices,dp);
        //dont sell
        int d=f(index+1,1,prices,dp);
        return dp[index][buy]= max(c,d);

    }
}
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        vector<vector<int>>dp(n,vector<int>(2,-1));
        int cv=f(0,0,prices,dp);
        return cv;
        
    }
};