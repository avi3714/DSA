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
        
        vector<vector<int>>dp(n+1,vector<int>(2,0));
        for(int i=n-1;i>=0;i--)
        {
            for(int j=0;j<2;j++)
            {
              if(j==1)
            {
                int a=prices[i]+dp[i+1][0];
                int b=dp[i+1][1];
                dp[i][j]=max(a,b);
            }
          else
          {
              int c= -prices[i]+dp[i+1][1];
              int d=dp[i+1][0];
               dp[i][j]=max(c,d);
          }  
               
            }
        }


        return dp[0][0];
        
    }
};