class Solution {
public:
void swapifgreater(vector<int>& nums1, int m, vector<int>& nums2, int n)
{
    if(nums1[m]>nums2[n])
    swap(nums1[m],nums2[n]);
}
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int len=(n+m);
        int gap=(len+1)/2;
        while(gap>0)
        {
            int left=0,right=left+gap;
            while(right<len)
            {
              if(left<m&& right>=m)
              swapifgreater(nums1,left,nums2,right-m);
              else if(right<m)
              swapifgreater(nums1,left,nums1,right);
              else
              swapifgreater(nums2,left-m,nums2,right-m);
              left++;right++;
            }
            if(gap==1)
            break;
            gap=(gap+1)/2;
        }
        for(int i=m;i<n+m;i++)
        {
            nums1[i]=nums2[i-m];
        }
        
    }
};