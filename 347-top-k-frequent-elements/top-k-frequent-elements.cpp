class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int n=nums.size();
        map<int,int>mpp;
        for(int i=0;i<n;i++)
        {
            mpp[nums[i]]++;
        }
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>q;
        for(auto it:mpp)
        {
                q.push({it.second,it.first});
            if(q.size()>k)
            {
                q.pop();
            }
           
        }
        vector<int>ans;
        while(!q.empty())
        {
            int y=q.top().second;
            ans.push_back(y);
            q.pop();
        }
        return ans;
        
    }
};