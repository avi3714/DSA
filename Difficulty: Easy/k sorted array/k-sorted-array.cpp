// User function template for C++

class Solution {
  public:
   void sort(int arr[],int n)
   {
       priority_queue<int>pq;
       for(int i=0;i<n;i++)
       {
           pq.push(arr[i]);
       }
       int i=n-1;
       while(!pq.empty())
       {
           int y=pq.top();
           pq.pop();
           arr[i]=y;
           i--;
       }
      
   }
  
    string isKSortedArray(int arr[], int n, int k) {
        // code here.
        map<int,int>mpp;
        for(int i=0;i<n;i++)
        {
            mpp[arr[i]]=i;
            
        }
        
        
        
        sort(arr,n);
        for(int i=0;i<n;i++)
        {
            if(abs(i-mpp[arr[i]]) <=k)
            continue;
            else
            return "No";
        }
        return "Yes";
    }
};