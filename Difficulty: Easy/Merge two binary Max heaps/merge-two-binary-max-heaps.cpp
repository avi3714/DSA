// User function Template for C++

class Solution {
  public:
  
   void heapify(vector<int>&a,int i,int n)
   {
       int largest=i;
       int left=2*i+1;
       int right=2*i+2;
       if(left<n && a[left]>a[largest])
       largest=left;
       if(right<n && a[right]>a[largest])
       largest=right;
       if(largest!=i)
       {
           swap(a[largest],a[i]);
           heapify(a,largest,n);
       }
   }
    vector<int> mergeHeaps(vector<int> &a, vector<int> &b, int n, int m) {
        // your code here
        int n1=a.size();
        int n2=b.size();
        for(auto it : b)
        {
            a.push_back(it);
        }
         n=n+m;
        
        for(int i=n/2;i>=0;i--)
        heapify(a,i,n);
        return a;
    }
};