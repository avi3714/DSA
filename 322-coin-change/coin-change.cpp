class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n=coins.size();
        vector<int>dp(amount+1,INT_MAX);
        if(amount==0)
        return 0;
        for(int i=0;i<n;i++)
        {
          if(coins[i]<=amount)
          dp[coins[i]]=1;
        }
        for(int i=1;i<=amount;i++)
        {
            if(dp[i]==INT_MAX)
            continue;
            for(int j=0;j<n;j++)
            {
                long  amt=coins[j];
                amt+=i;
                long y=amount;
                if(amt<=y)
                dp[i+coins[j]]=min(dp[i+coins[j]],1+dp[i]);

            }
        }
        if(dp[amount]==INT_MAX)
        return -1;
        return dp[amount];
        
    }
};