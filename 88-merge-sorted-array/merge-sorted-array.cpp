class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        
        if(m==0){
        nums1=nums2;}
        else
        {

        int i=m-1,j=n-1,k=m-1+n;
        while(j>=0 && i>=0)
        {
            if(nums1[i]>nums2[j])
            {
                 swap(nums1[i],nums1[k]);
                 i--;k--;
            }
            else
            {
                nums1[k]=nums2[j];
                j--;k--;
            }
        }
        while(j>=0)
        {
            nums1[k]=nums2[j];
            j--;k--;
        }
        }
    }
};