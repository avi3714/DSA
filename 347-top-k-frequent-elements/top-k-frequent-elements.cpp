class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int n=nums.size();
        unordered_map<int,int>mpp;
        for(int i=0;i<n;i++)
        mpp[nums[i]]++;
        vector<vector<int>>freq(n+1);
        for(auto it:mpp)
        {
            freq[it.second].push_back(it.first);
        }
        vector<int>result;
        for(int i=n;i>=0;i--)
        {
            for(int j=0;j<freq[i].size();j++)
            {
                result.push_back(freq[i][j]);
                if(result.size()>=k)
                break;
            }
            if(result.size()>=k)
            break;
        }
        return result;
        
    }
};