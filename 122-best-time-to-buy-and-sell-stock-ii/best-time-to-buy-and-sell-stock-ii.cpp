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
        
       // vector<vector<int>>dp(n+1,vector<int>(2,0));
        vector<int>prev(2,0),curr(2,0);
        for(int i=n-1;i>=0;i--)
        {
            for(int j=0;j<2;j++)
            {
              if(j==1)
            {
                int a=prices[i]+prev[0];
                int b=prev[1];
                curr[j]=max(a,b);
            }
          else
            {
              int c= -prices[i]+prev[1];
              int d=prev[0];
               curr[j]=max(c,d);
          }  
               
            }
            prev=curr;
        }


        return curr[0];
        
    }
};