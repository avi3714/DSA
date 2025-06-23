class Solution {
public:
int f(int i,int j,string s,string t,vector<vector<int>>&dp)
{
    
    if(j<0)
    return 1;
    if(i<0)return 0;
    if(dp[i][j]!=-1)
    return dp[i][j];
    if(s[i]==t[j])
    return dp[i][j]=f(i-1,j-1,s,t,dp) + f(i-1,j,s,t,dp);
    else
    return dp[i][j]=f(i-1,j,s,t,dp);
}
    int numDistinct(string s, string t) {
        int n1=s.length()-1;
        int n2=t.length()-1;
        vector<vector<int>>dp(n1+1,vector<int>(n2+1,-1));
        return f(n1,n2,s,t,dp);
        
    }
};