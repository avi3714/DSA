class Solution {
public:
int f(int i,int j,vector<int>&nums,vector<vector<int>>&dp)
{
    if(i>j)
    return 0;
    if(dp[i][j]!=-1)
    return dp[i][j];
    int maxi=INT_MIN;
    for(int ind=i;ind<=j;ind++)
    {
        int ans=nums[i-1]*nums[ind]*nums[j+1];
        ans+=f(i,ind-1,nums,dp)+f(ind+1,j,nums,dp);
        maxi=max(maxi,ans);
    }
    return dp[i][j]= maxi;
}
    int maxCoins(vector<int>& nums) {
        
        nums.push_back(1);
        nums.insert(nums.begin(),1);
        int n=nums.size();
        vector<vector<int>>dp(n-1,vector<int>(n-1,0));
        for(int i=n-2;i>=1;i--)
        {
            for(int j=i;j<=n-2;j++)
            {
                int maxi=INT_MIN;
                for(int ind=i;ind<=j;ind++)
                {
                  int ans=nums[i-1]*nums[ind]*nums[j+1];
                  ans+=f(i,ind-1,nums,dp)+f(ind+1,j,nums,dp);
                 maxi=max(maxi,ans);
                }
                dp[i][j]= maxi;
            }
        }
        return dp[1][n-2];

    }
};