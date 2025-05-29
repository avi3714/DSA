class StockSpanner {
public:
        stack<pair<int,int>>stock;
    StockSpanner() {
    }
    
    int next(int price) {
        int count=1;
        while(!stock.empty()&&stock.top().first<=price)
        {
            count=count+stock.top().second+1;
            stock.pop();
        }
        stock.push({price,count-1});
        return count;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */