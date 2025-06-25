class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        //n log n solution,only for finding length.
        int n=nums.size();
        vector<int>temp;
        temp.push_back(nums[0]);
        for(int i=1;i<n;i++)
        {
            if(nums[i]> temp.back())
            temp.push_back(nums[i]);
            else 
            {
                int y=lower_bound(temp.begin(),temp.end(),nums[i])-temp.begin();
                temp[y]=nums[i];
            }
        }
        return temp.size();
        
    }
};