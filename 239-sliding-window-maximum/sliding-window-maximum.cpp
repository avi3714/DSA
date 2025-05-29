class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        multiset<int>st;
        int n=nums.size();
        int i=0;
        while(i<k){
        st.insert(nums[i]);
        i++;}
        vector<int>answer;
        answer.push_back(*prev(st.end()));
        while(i<n)
        {
            st.insert(nums[i]);
            auto it=st.find(nums[i-k]);
            st.erase(it);
            answer.push_back(*prev(st.end()));
            i++;
        }
        return answer;
        
    }
};