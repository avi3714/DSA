class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        int mini=prices[0];
        int maxi=0;
        
        for(int i=1;i<n;i++)
        {
            int cost=prices[i]-mini;
            maxi=max(maxi,cost);
            mini=min(mini,prices[i]);
        }
        return maxi;
        
    }
};