class KthLargest {
public:
priority_queue<int,vector<int>,greater<int>>q;
int k1;
int maxi=INT_MIN;
    KthLargest(int k, vector<int>& nums) {
        k1=k;
        for(auto it:nums)
        {
            if(q.size()<k)
          q.push(it);
        else
        {
            if(it>q.top())
            {
                q.pop();
                q.push(it);
            }
        
        //4 5 8
        }
        }
        
    }
    
    int add(int val) {
        
        if(q.size()<k1)
        q.push(val);
        
            else if(val>q.top())
            {
                q.pop();
                q.push(val);
            }
            // 5 8 10
        
        return q.top();
        
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */