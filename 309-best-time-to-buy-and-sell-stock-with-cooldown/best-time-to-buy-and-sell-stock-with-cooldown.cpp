class Solution {
public:
int f(int index,int buy,vector<int>&prices,vector<vector<int>>&dp)
{
    if(index>=prices.size())
    return 0;
    //not bought
    if(dp[index][buy]!=-1)
    return dp[index][buy];
    if(buy==0)
    {
        //buy it
        int a=-prices[index]+f(index+1,1,prices,dp);
        //dont buy it
        int b=f(index+1,0,prices,dp);
        return dp[index][buy]= max(a,b);
    }
    else
    {
        //bought
        //sell it
        int c=prices[index]+f(index+2,0,prices,dp);
        //dont sell
        int d=f(index+1,1,prices,dp);
        return dp[index][buy]= max(c,d);

    }
}
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        vector<int>front1(2,0),front2(2,0),curr(2,0);
        for(int index=n-1;index>=0;index--)
        {
           
                //buy it
                int a=-prices[index]+front1[1];
                 //dont buy it
                int b=front1[0];
                 curr[0]= max(a,b);
                                
                   
                
                //bought
                  //sell it
                  int c=prices[index]+front2[0];
                  //dont sell
                  int d=front1[1];
                  curr[1]= max(c,d);

               front2=front1;
               front1=curr;

           
        }
        int cv=curr[0];
        return cv;
        
    }
};