class Solution {
public:
int f(string word1, string word2,int i,int j){
    if(i<0 )
    return j+1;
    if(j<0)
    return i+1;

    if(word1[i]==word2[j])
    return f(word1,word2,i-1,j-1);
    int a=1+f(word1,word2,i,j-1);
    int b=1+f(word1,word2,i-1,j);
    int c=1+f(word1,word2,i-1,j-1);
    return min(min(a,b),c);
}
    int minDistance(string word1, string word2) {
        int n1=word1.size();
        int n2=word2.size();
        vector<vector<int>>dp(n1+1,vector<int>(n2+1,0));
        for(int i=0;i<=n1;i++)
        {
            dp[i][0]=i;
        }
        for(int i=0;i<=n2;i++)
        {
            dp[0][i]=i;
        }
        for(int i=1;i<=n1;i++)
        {
            for(int j=1;j<=n2;j++)
            {
                if(word1[i-1]==word2[j-1])
                {
                    dp[i][j]=dp[i-1][j-1];
                }
                else
                {
                    dp[i][j]=min(dp[i][j-1],min(dp[i-1][j],dp[i-1][j-1]))+1;
                }
            }
        }
        return dp[n1][n2];
    }
};