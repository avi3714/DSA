class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n=nums.size();
        stack<int>st;
        vector<int>hash(n,-1);
        
        
        for(int i=2*n-1;i>=0;i--)
        {
            int index=i%n;
            
            
            while(!st.empty()&&st.top()<=nums[index])
            {
                st.pop();
            }
            if(i<n && !st.empty())
            hash[i]=st.top();
            
            st.push(nums[i%n]);
        }
        
        return hash;
    }
};