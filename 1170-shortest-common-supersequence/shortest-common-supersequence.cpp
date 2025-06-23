class Solution {
public:
void getdptable(string s1,string s2,vector<vector<int>>&dp)
{
    int n1=s1.length();
    int n2=s2.length();
    for(int i=1;i<=n1;i++)
    {
        for(int j=1;j<=n2;j++)
        {
            if(s1[i-1]==s2[j-1])
            dp[i][j]=1+dp[i-1][j-1];
            else
            dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
        }
    }
}
string getthestring(int n1,int n2,vector<vector<int>>&dp,string s1,string s2)
{
  string finalans="";
  while(n1>0 && n2>0)
  {
    if(s1[n1-1]==s2[n2-1]){
    finalans.push_back(s1[n1-1]);
    n1--;n2--;}
    else if(dp[n1][n2-1]<=dp[n1-1][n2])
    {
        finalans.push_back(s1[n1-1]);
        n1--;
    }
    else
    {
        finalans.push_back(s2[n2-1]);
        n2--;
    }
  }
  while(n1>0)
  {
    finalans.push_back(s1[n1-1]);
    n1--;
  }
  while(n2>0)
  {
    finalans.push_back(s2[n2-1]);
    n2--;
  }
  return finalans;
}
    string shortestCommonSupersequence(string str1, string str2) {
        int n1=str1.length();
        int n2=str2.length();
        vector<vector<int>>dp(n1+1,vector<int>(n2+1,0));
        getdptable(str1,str2,dp);
        cout<<dp[n1][n2]<<endl;
        string s4=getthestring(n1,n2,dp,str1,str2);
        reverse(s4.begin(),s4.end());
        return s4;
    }
};
