class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {

 map<int,int>mpp;
 int n=nums.size();
 int count=0,sum=0;
 for(int i=0;i<n;i++)
 {
    sum+=nums[i];
    if(sum==k)
    count++;
    count=count+(mpp[sum-k]);
    mpp[sum]++;
 }
 return count;













    //   map<int,int>mpp;
    //   mpp[0]=1;
    //   int s=0,count=0;
    //   int y=nums.size();
  
    //     for(int i=0;i<y;i++)
    //   {     
    //  s=s+nums[i];
    //      int rem=s-k;
    //     count=count+ mpp[rem];
    //     mpp[s]++;
    //   } 
    //   return count; 
    
    }
};