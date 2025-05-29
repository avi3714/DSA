class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n=heights.size();
        stack<int>st;
        int maxi=INT_MIN;
        for(int i=0;i<n;i++)
        {
            while(!st.empty()&&heights[st.top()]>=heights[i])
            {
                int r=st.top();
                st.pop();
                int nse=i;
                int pse=(st.empty())?-1:st.top();
                maxi=max(maxi,(nse-pse-1)*heights[r]);
            }
            st.push(i);
        }
        while(!st.empty())
        {
            int nse=n;
            int r=st.top();
             st.pop();
            int pse=(st.empty())?-1:st.top();
            maxi=max(maxi,(nse-pse-1)*heights[r]);

        }   
        return maxi;
    }
};