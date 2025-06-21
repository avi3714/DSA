class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int n=nums.size();
        int sum=accumulate(nums.begin(),nums.end(),0);
        if(sum%2==1)
        return false;
        int target=sum/2;
        vector<bool>prev(target+1,false),curr(target+1,false);
        prev[0]=curr[0]=true;
        if(nums[0]<=target)
        prev[nums[0]]=true;
        for(int i=1;i<n;i++)
        {
            for(int targ=1;targ<=target;targ++)
            {
                  bool nottake=prev[targ];
                  bool take=false;
                  if(targ>=nums[i])
                  take=prev[targ-nums[i]];
                  curr[targ]=take|nottake;
            }
            prev=curr;
        }
        return curr[target];

        
    }
};