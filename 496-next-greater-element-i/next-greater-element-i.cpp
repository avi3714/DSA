class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int n=nums2.size();
        vector<int>hash(n,-1);
        map<int,int>mpp;
        stack<int>st;
        for(int i=n-1;i>=0;i--)
        {
            mpp[nums2[i]]=i;
            if(st.empty())
            {
                st.push(nums2[i]);
                continue;
            }
            while(!st.empty())
            {
                if(st.top()>nums2[i]){
                hash[i]=st.top();
                break;}
                else
                st.pop();
            }
            st.push(nums2[i]);
        }
        vector<int>ans;
        for(int i=0;i<nums1.size();i++)
        {
            int a=mpp[nums1[i]];
            ans.push_back(hash[a]);
        }
        return ans;

        
    }
};