class Solution {
public:
int maxarea(vector<int>&v)
{
    int n=v.size();
    stack<int>st;
    vector<int>nse(n,n);
    vector<int>pse(n,-1);
    for(int i=0;i<n;i++)
    {
        while(!st.empty()&&v[st.top()]>=v[i])
        st.pop();
        if(!st.empty())
        pse[i]=st.top();
        st.push(i);
    }
    while(!st.empty())
    st.pop();
    for(int i=n-1;i>=0;i--)
    {
        while(!st.empty()&& v[st.top()]>=v[i])
        st.pop();
        if(!st.empty())
        nse[i]=st.top();
        st.push(i);
    }
    int localmax=0;
    for(int i=0;i<n;i++)
    {
        if(v[i]==0)
       continue;
        localmax=max(localmax, (nse[i]-1-pse[i])*v[i]);
    }
    return localmax;
}
    int maximalRectangle(vector<vector<char>>& matrix) {
        int rows=matrix.size();
        int cols=matrix[0].size();
        vector<vector<int>>prefixsum(rows,vector<int>(cols,0));
        for(int i=0;i<rows;i++)
        {
            for(int j=0;j<cols;j++)
            {
                if(matrix[i][j]=='0')
                prefixsum[i][j]=0;
                else
                {
                prefixsum[i][j]=1;
                if(i>0)
                prefixsum[i][j]+=prefixsum[i-1][j];}
            }
        }
        int maxiareai=0;
        for(int i=0;i<rows;i++)
        {
            maxiareai=max(maxiareai,maxarea(prefixsum[i]));
        }
        return maxiareai;

        
    }
};