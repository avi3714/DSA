class Solution {
public:
bool isPalindrome(int i,int j,string &s,vector<vector<int>>&dp2)
{
    int a=i,b=j;
    if(dp2[i][j]!=-1)
    return dp2[i][j];
    while(i<=j)
    {
        if(s[i]!=s[j])
        return dp2[a][b]= false;
        i++;j--;
    }
    return dp2[a][b]= true;
}
int f(int i,int n,string &s,vector<int>&dp,vector<vector<int>>&dp2)
{
    if(i==n)
    return 0;
     int mini=INT_MAX;
     if(dp[i]!=-1)
     return dp[i];
     for(int ind=i;ind<n;ind++)
     {
        if(isPalindrome(i,ind,s,dp2)){
        int ans=1+f(ind+1,n,s,dp,dp2);
        mini=min(mini,ans);}
     }
     return dp[i]=mini;
}
    int minCut(string s) {
        int n=s.length();
        vector<int>dp(n+1,0);
        vector<vector<int>>dp2(n,vector<int>(n,-1));
        for(int i=n-1;i>=0;i--)
        {
             int mini=INT_MAX;
            for(int ind=i;ind<n;ind++)
            {
                if(isPalindrome(i,ind,s,dp2)){
               int ans=1+dp[ind+1];
               mini=min(mini,ans);}         
            }
            dp[i]=mini;
        }
        return dp[0] -1;
        
    }
};