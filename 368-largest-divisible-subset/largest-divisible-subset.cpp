class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        vector<pair<int,int>>dp;
        for(int i=0;i<n;i++)
        {
            dp.push_back({1,i});
        }
        int maxi=1;
        int maxindex=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<i;j++)
            {
                if(nums[i]%nums[j]==0)
                {
                    if(1+dp[j].first > dp[i].first)
                    {
                        dp[i].first=1+dp[j].first;
                        dp[i].second=j;
                    }
                }
            }
            if(dp[i].first > maxi)
            {
                maxi=dp[i].first;
                maxindex=i;
            }
        }
        vector<int>v;
        while(maxi--)
        {
            v.push_back(nums[maxindex]);
            maxindex=dp[maxindex].second;
        }
        return v;
        
    }
};