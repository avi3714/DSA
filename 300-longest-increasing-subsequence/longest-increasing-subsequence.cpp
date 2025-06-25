class Solution {
public:
int f(int index,int prev_index,vector<int>& nums,vector<vector<int>>&dp)
{
    int n=nums.size();
    if(index<0)
    return 0;
    if(dp[index][prev_index]!=-1)
    return dp[index][prev_index];
     int nottake=f(index-1,prev_index,nums,dp);
     int take=0;
     if(prev_index==n || nums[index] < nums[prev_index])
     take=1+f(index-1,index,nums,dp);
     return dp[index][prev_index]= max(take,nottake);
}
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>>dp(n,vector<int>(n+1,-1));
        return f(n-1,n,nums,dp);
        
    }
};