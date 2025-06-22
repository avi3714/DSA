class Solution {
public:
int f(int index,int target,vector<int>& nums)
{
    if(index==0)
    {
        if(target==0&&nums[0]==0)
        return 2;
        if(nums[index]==target||nums[index]==-1*target)
        return 1;
        else
        return 0;
    }
    int plus=f(index-1,target-nums[index],nums);
    int minus=f(index-1,target+nums[index],nums);
    return plus+minus;
}
    int findTargetSumWays(vector<int>& nums, int target) {
        int n=nums.size();
        return f(n-1,target,nums);
    }
};