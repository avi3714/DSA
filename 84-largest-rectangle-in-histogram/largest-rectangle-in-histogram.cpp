class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n=heights.size();
        stack<int>st;
        vector<int>pse(n,-1);
        for(int i=0;i<n;i++)
        {
            while(!st.empty()&&heights[st.top()]>=heights[i])
            {
                st.pop();
            }
            if(!st.empty())
            {
                pse[i]=st.top();
            }

        st.push(i);
        }
        while(!st.empty())
        st.pop();
        vector<int>nse(n,n);
        for(int i=n-1;i>=0;i--)
        {
            while(!st.empty()&&heights[st.top()]>=heights[i])
            st.pop();
            if(!st.empty())
            nse[i]=st.top();
            st.push(i);

        }
        int maxi=0;
        for(int i=0;i<n;i++)
        {
            maxi=max(((nse[i]-pse[i]-1)*heights[i]),maxi);
        }
        return maxi;
    }
};