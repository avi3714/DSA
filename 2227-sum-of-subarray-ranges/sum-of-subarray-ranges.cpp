class Solution {
public:
    long long subArrayRanges(vector<int>& nums) {
        int n=nums.size();
        //precompute next samller element
        vector<int>nse(n,n);
        stack<int>st;
        for(int i=n-1;i>=0;i--)
        {
            while(!st.empty()&&nums[st.top()]>=nums[i])
            st.pop();
            if(!st.empty())
            nse[i]=st.top();
            st.push(i);
        }
        while(!st.empty())
        st.pop();
        vector<int>psee(n,-1);
        for(int i=0;i<n;i++)
        {
            while(!st.empty()&&nums[st.top()]>nums[i])
            st.pop();
            if(!st.empty())
            psee[i]=st.top();
            st.push(i);
        }
        while(!st.empty())
        st.pop();
        vector<int>nge(n,n);
         for(int i=n-1;i>=0;i--)
        {
            while(!st.empty()&&nums[st.top()]<=nums[i])
            st.pop();
            if(!st.empty())
            nge[i]=st.top();
            st.push(i);
        }
        while(!st.empty())
        st.pop();
        vector<int>pgee(n,-1);
         for(int i=0;i<n;i++)
        {
            while(!st.empty()&&nums[st.top()]<nums[i])
            st.pop();
            if(!st.empty())
            pgee[i]=st.top();
            st.push(i);
        }
        long long sum=0;
        for(int i=0;i<n;i++)
        {
            long long count=(i-psee[i])*(nse[i]-i);
            long long count2=(nge[i]-i)*(i-pgee[i]);
            sum+=(count2-count)*nums[i];
        }
        return sum;


    }
};