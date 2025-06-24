class Solution {
public:
int f(int index,int buy,int qnty,vector<int>&prices,int n,vector<vector<vector<int>>>&dp)
{
    if(qnty>=2)
    return 0;
    if(index>=n)
    return 0;
    if(dp[index][buy][qnty]!=-1)
    return dp[index][buy][qnty];
     if(buy==0)
     {
        int a=-prices[index]+f(index+1,1,qnty,prices,n,dp);
        int b=f(index+1,0,qnty,prices,n,dp);
        return dp[index][buy][qnty]= max(a,b);
     }
     else
     {
        int c=prices[index]+f(index+1,0,qnty+1,prices,n,dp);
        int d=f(index+1,1,qnty,prices,n,dp);
        return dp[index][buy][qnty]= max(c,d);
     }
}
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        vector<vector<vector<int>>>dp(n,vector<vector<int>>(2,vector<int>(2,-1)));
        return f(0,0,0,prices,n,dp);
        
    }
};