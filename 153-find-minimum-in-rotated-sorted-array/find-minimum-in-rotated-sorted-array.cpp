class Solution {
public:
    int findMin(vector<int>& nums) {
        int n=nums.size();
        if(n==1)
        return nums[0];
        if(n==2)
        return min(nums[0],nums[1]);
        int low=0,high=n-1;
        if(nums[0] < nums[n-1])
        return nums[0];
        while(low<=high)
        {
            int mid=(low+high)/2;
            if(nums[mid] < nums[(mid-1+n)%n] && nums[mid] < nums[(mid+1)%n])
            return nums[mid];
           if(nums[mid] >= nums[0])
           {
              low=mid+1;
           }
           else 
           high=mid-1;
        }
        return -1;
    }
};