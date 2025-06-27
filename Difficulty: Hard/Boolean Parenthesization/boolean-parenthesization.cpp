// User function Template for C++
class Solution {
  public:
  int f(int i,int j,string &s,int count,vector<vector<vector<int>>>&dp)
  {
      if(i==j)
      {
          if(count==1)
          {
              if(s[i]=='T')
              return 1;
              else
              return 0;
          }
          else{
              if(s[i]=='F')
              return 1;
              else
              return 0;
          }
      }
      if(dp[i][j][count]!=-1)
      return dp[i][j][count];
      int ways=0;
      for(int ind=i+1;ind<j;ind+=2)
      {
          int lt=f(i,ind-1,s,1,dp);
          int lf=f(i,ind-1,s,0,dp);
          int rt=f(ind+1,j,s,1,dp);
          int rf=f(ind+1,j,s,0,dp);
          if(s[ind]=='|')
          {
              if(count==1)
              {
                  ways+= lt*rt + lt*rf + lf*rt;
              }
              else
              {
                  ways+= rf*lf;
              }
          }
          else if(s[ind]=='^')
          {
              if(count==1)
              {
                  ways+= lf*rt+ rf*lt;
              }
              else
              ways+= rt*lt+rf*lf;
          }
          else
          {
              if(count==1)
              {
                  ways+= lt*rt;
              }
              else
               ways+= lt*rf+ lf*rt + lf*rf;
          }
      }
      return dp[i][j][count]= ways;
  }
  
    int countWays(string &s) {
        // code here
        int n=s.length();
        vector<vector<vector<int>>>dp(n,vector<vector<int>>(n,vector<int>(2,-1)));
        return f(0,n-1,s,1,dp);
        
        
    }
};