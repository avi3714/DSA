class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end());
        int n=intervals.size();
        vector<vector<int>>ans;
        int start=intervals[0][0],end=intervals[0][1];
        if(n==1)
        ans.push_back(intervals[0]);
        for(int i=1;i<n;)
        {
             while(i<n && intervals[i][0]<=end)
             {
                end=max(intervals[i][1],end);
                i++;
             }
             ans.push_back({start,end});
             if(i<n)
             {
             start=intervals[i][0];
             end=intervals[i][1];
             }
        }
        return ans;
        
    }
};