class Solution {
public:
int f(int index,int transaction,vector<int>& prices,vector<vector<int>>&dp)
{
    //B S B S
    //if(i is even then buy)
    if(index>=prices.size())
    return 0;
    if(transaction>=4)
    return 0;
    if(dp[index][transaction]!=-1)
    return dp[index][transaction];
    if(transaction%2==0)
    {
        int a=-prices[index]+f(index+1,transaction+1,prices,dp);
        int b=f(index+1,transaction,prices,dp);
        return dp[index][transaction]=max(a,b);
    }
    else
    {
        int c=prices[index]+f(index+1,transaction+1,prices,dp);
        int d=f(index+1,transaction,prices,dp);
        return dp[index][transaction]=max(c,d);
    }
}
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        vector<vector<int>>dp(n,vector<int>(4,-1));
        return f(0,0,prices,dp);
    }
};