class Solution {
  public:
    vector<int> getLIS(vector<int>& arr) {
        // Code here
        int n=arr.size();
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
                if(arr[i] > arr[j] && dp[i].first < 1+dp[j].first)
                {
                    dp[i].first = 1+dp[j].first;
                    dp[i].second=j;
                }
            }
            if(dp[i].first>maxi)
            {
                maxi=dp[i].first;
                maxindex=i;
            }
        }
        vector<int>v;
        while(maxi--)
        {
            v.push_back(arr[maxindex]);
            maxindex=dp[maxindex].second;
        }
        reverse(v.begin(),v.end());
        return v;
    }
};