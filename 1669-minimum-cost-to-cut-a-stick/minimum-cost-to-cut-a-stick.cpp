class Solution {
public:
int f(int start,int end,vector<int>&cuts,vector<vector<int>>&dp)
{
    if(start+1==end||start==end)
    return 0;
    if(dp[start][end]!=-1)
    return dp[start][end];
    int mini=INT_MAX;
    for(int i=start+1;i<end;i++)
    {
        int ans=f(start,i,cuts,dp)+f(i,end,cuts,dp)+cuts[end]-cuts[start];
        mini=min(mini,ans);
    }
    return dp[start][end]= mini;
}
    int minCost(int n, vector<int>& cuts) {
        cuts.push_back(0);
        cuts.push_back(n);
        sort(cuts.begin(),cuts.end());
        int cutsize=cuts.size();
        vector<vector<int>>dp(cutsize,vector<int>(cutsize,-1));
        return f(0,cutsize-1,cuts,dp);
        
    }
};