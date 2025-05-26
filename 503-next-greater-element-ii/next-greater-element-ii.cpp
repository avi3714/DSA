class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n=nums.size();
        stack<int>st;
        for(int i=0;i<n;i++)
        {
            nums.push_back(nums[i]);
        }
        n=nums.size();
        vector<int>hash(n,-1);
        for(int i=n-1;i>=0;i--)
        {
            if(st.empty())
            {
                st.push(nums[i]);
                continue;
            }
            while(!st.empty())
            {
                if(st.top()>nums[i]){
                hash[i]=st.top();
                break;}
                else
                st.pop();
            }
            st.push(nums[i]);
        }
        vector<int>anw(hash.begin(),hash.begin()+(n/2));
        return anw;
    }
};