
class Solution {
  public:
    bool isMaxHeap(int arr[], int n) {
        // Your code goes here
        //int n=arr.size();
        for(int i=n-1;i>0;i--)
        {
            if(arr[i]<=arr[(i-1)/2])
            continue;
            else
           return false;
        }
        return true;
    }
};