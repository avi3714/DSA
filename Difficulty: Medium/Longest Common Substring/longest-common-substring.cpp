class Solution {
  public:
    int longestCommonSubstr(string& s1, string& s2) {
        // your code here
      int n1=s1.length();
      int n2=s2.length();
      vector<vector<int>>dp(n1+1,vector<int>(n2+1,0));
      for(int i=1;i<=n1;i++)
      {
         for(int j=1;j<=n2;j++)
         {
               if(s1[i-1]==s2[j-1])
               {
                   if(i-2>=0 && j-2>=0 && s1[i-2]==s2[j-2])
                   {
                       dp[i][j]=1+dp[i-1][j-1];
                   }
                   else
                   {
                       dp[i][j]=1;
                   }
               }
         }
      }int maxi=0;
      for(int i=1;i<=n1;i++)
      {
          for(int j=1;j<=n2;j++)
          {
              maxi=max(maxi,dp[i][j]);
          }
      }
      return maxi;
    }
};