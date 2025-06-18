// User function Template for C++

class Solution {
  public:

    vector<int> replaceWithRank(vector<int> &arr, int N) {
        map<int,int>mpp;
        priority_queue<int,vector<int>,greater<int>>q;
        for(int i=0;i<arr.size();i++)
        {
            if(mpp[arr[i]]==0)
            {
                mpp[arr[i]]=i;
                q.push(arr[i]);
                
            }
            mpp[arr[i]]++;
        }
        int p=1;
        while(!q.empty())
        {
            int it=q.top();
            q.pop();
            mpp[it]=p;
            p++;
        }
        vector<int>ans;
        for(auto it:arr)
        {
            ans.push_back(mpp[it]);
        }
        return ans;
    }
};
