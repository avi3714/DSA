class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        int n=nums.size();
        priority_queue<int,vector<int>,greater<int>>q;
        for(int i=0;i<n;i++)
        {
            if(q.size()<k)
            {
                q.push(nums[i]);
                continue;
            }
            if(nums[i]>q.top())
            {
                q.pop();
                q.push(nums[i]);
            }
        }
        return q.top();
    }
};