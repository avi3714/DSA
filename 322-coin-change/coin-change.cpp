class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        sort(coins.begin(),coins.end());
        vector<bool>visited(amount+1,false);
        queue<pair<int,int>>q;
        for(auto it: coins)
        {
            q.push({it,1});
            if(it<=amount)
            visited[it]=true;

        }
        if(amount==0)
        return 0;
        int ans=-1;

        while(!q.empty())
        {
            pair<int,int>r=q.front();
            q.pop();
            if(r.first==amount)
            {
                ans=r.second;
                break;
            }
            //return r.second;          
           // return -1;
            else
            {
                for(int i=0;i<coins.size();i++)
                {
                    long long qnty=1LL*(r.first)+1LL*coins[i];
                    if(qnty<=amount && visited[r.first+coins[i]]==false){
                    q.push({r.first+coins[i],r.second+1});
                    visited[r.first+coins[i]]=true;}
                }
            }
        }
        return ans;
        
    }
};