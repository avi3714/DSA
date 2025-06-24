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
       // vector<vector<vector<int>>>dp(n+1,vector<vector<int>>(2,vector<int>(3,0)));
        vector<vector<int>>prev(2,vector<int>(3,0)),curr(2,vector<int>(3,0));
        for(int index=n-1;index>=0;index--)
        {
            for(int buy=0;buy<2;buy++)
            {
                for(int qnty=0;qnty<2;qnty++)
                {
                       if(buy==0)
                    {
                      int a=-prices[index]+prev[1][qnty];
                      int b=prev[0][qnty];
                       curr[buy][qnty]= max(a,b);
                     }

                      else
                       {
                         int c=prices[index]+prev[0][qnty+1];
                         int d=prev[1][qnty];
                         curr[buy][qnty]= max(c,d);
                       }
          }
            }
        prev=curr;
        }


        return curr[0][0];
        
    }
};