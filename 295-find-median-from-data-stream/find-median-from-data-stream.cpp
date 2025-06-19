class MedianFinder {
public:
priority_queue<int>maxheap;
priority_queue<int,vector<int>,greater<int>>minheap;
double median=-1;
int signum(int a,int b)
{
    if(a==b)
    return 0;
    else if(a>b)
    return 1;
    else
    return -1;
}
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        switch(signum(maxheap.size(),minheap.size()))
        {
            case 0:{
                if(num>median)
                {
                    minheap.push(num);
                    median=minheap.top();
                }
                else
                {
                    maxheap.push(num);
                    median=maxheap.top();
                }
                break;
            }
            case 1:{
                if(num>median)
                {
                    minheap.push(num);
                }
                else
                {
                    minheap.push(maxheap.top());
                    maxheap.pop();
                    maxheap.push(num);
                    
                }
                    median=((1.00)*(maxheap.top()+minheap.top()))/2;
                break;
            }
            case -1:{
                 if(num>median)
                 {
                    maxheap.push(minheap.top());
                    minheap.pop();
                    minheap.push(num);
                 }
                 else
                 {
                    maxheap.push(num);
                   
                 }
                    median=((1.00)*(maxheap.top()+minheap.top()))/2;
                break;
            }
        }
        
    }
    
    double findMedian() {
        return median;
        
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */