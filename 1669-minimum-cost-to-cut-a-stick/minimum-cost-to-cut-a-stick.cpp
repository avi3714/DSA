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
        vector<vector<int>>dp(cutsize,vector<int>(cutsize,0));
        //start is from 0 to cutsize-1
        for(int start=cutsize-1;start>=0;start--)
        { 
            for(int end=start+2;end<cutsize;end++)
            {    int mini=INT_MAX;
                 for(int i=start+1;i<end;i++)
                     {
                       int ans=dp[start][i]+dp[i][end]+cuts[end]-cuts[start];
                       mini=min(mini,ans);
                     }
            if(mini!=INT_MAX)
            dp[start][end]=mini;
            }
        }
        return dp[0][cutsize-1];
        
    }
};