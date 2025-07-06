class Solution {
public:
    int findMin(vector<int>& nums) {
        int n=nums.size();
        if(n==1)
        return nums[0];
        if(n==2)
        return min(nums[0],nums[1]);
        int low=0,high=n-1;
        int mini=INT_MAX;
        while(low<=high)
        {
            int mid=(low+high)/2;
            if(nums[mid] < nums[(mid+1)%n] && nums[mid] < nums[(mid-1+n)%n])
            return nums[mid];
            else if(nums[mid] < nums[high])
            high=mid;
            else if(nums[mid] > nums[low])
            {
             mini=min(mini,nums[low]);
            low=mid+1;
            }
            else
            low++;
        }
        return min(mini, nums[high]);
        
    }
};