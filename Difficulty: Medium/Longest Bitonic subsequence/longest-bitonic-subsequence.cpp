
class Solution {
  public:
    int LongestBitonicSequence(int n, vector<int> &nums) {
        // code here
        vector<int>dp(n,1),dp2(n,1);
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<i;j++)
            {
                if(nums[i]>nums[j])
                {
                    dp[i]=max(1+dp[j],dp[i]);
                }
            }
        }
        
        for(int i=n-1;i>=0;i--)
        {
            for(int j=n-1;j>i;j--)
            {
                if(nums[i]>nums[j])
                {
                    dp2[i]=max(1+dp2[j],dp2[i]);
                }
            }
        }
        
        int maxi=0;
        for(int i=0;i<n;i++)
        {
            if(dp[i]>1 && dp2[i]>1)
            maxi=max(dp[i]+dp2[i]-1,maxi);
        }
        return maxi;
        
    }
};
