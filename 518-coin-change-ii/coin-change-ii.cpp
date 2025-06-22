class Solution {
public:
int f(int index,int target,vector<int>&coins,vector<vector<int>>&dp)
{
    if(dp[index][target]!=-1)
    return dp[index][target];
    // if(index==0)
    // {   
    //     return target%coins[index]==0;
    // }
    int nottake=f(index-1,target,coins,dp);
    int take=0;
    if(target>=coins[index])
     take=f(index,target-coins[index],coins,dp);
     return dp[index][target]=take+nottake;
}
    int change(int amount, vector<int>& coins) {
        int n=coins.size();
        vector<long >prev(amount+1,0),curr(amount+1,0);
        for(int target=0;target<=amount;target++)
        {
            prev[target]=((target%coins[0])==0);
        }
        //curr=prev;
        for(int index=1;index<n;index++)
        {
            for(int target=0;target<=amount;target++)
            {
                int nottake=prev[target];
                int take=0;
                if(coins[index]<=target)
                take=curr[target-coins[index]];
                curr[target]=take;
                curr[target]=curr[target]+nottake;
            }
            prev=curr;
        }
        int ans=(int)prev[amount];
        return ans;
        
    }
};