class Solution {
public:
int maxp(int k,vector<int>& prices) {
        int n=prices.size();
        vector<vector<int>>prev(2,vector<int>(k+2,0)),curr(2,vector<int>(k+2,0));
        for(int index=n-1;index>=0;index--)
        {
            for(int buy=0;buy<2;buy++)
            {
                for(int qnty=0;qnty<=k;qnty++)
                {
                       if(buy==0)
                    {
                      int a=-prices[index]+prev[1][qnty];
                      int b=prev[0][qnty];
                       curr[buy][qnty]= max(a,b);
                     }

                      else
                       {
                        if(qnty<k)
                        {

                        
                         int c=prices[index]+prev[0][qnty+1];
                         int d=prev[1][qnty];
                         curr[buy][qnty]= max(c,d);
                        }
                         else
                         {
                           
                         int d=prev[1][qnty];
                         curr[buy][qnty]= d; 
                         }
                       }
          }
            }
        prev=curr;
        }


        return curr[0][0];
        
    }
    int maxProfit(int k, vector<int>& prices) {
        return maxp(k,prices);
    }
};