class Solution {
public:
int x[4]={0,0,1,-1};
int y[4]={1,-1,0,0};
    int swimInWater(vector<vector<int>>& grid) {
        int n=grid.size();
        vector<vector<int>>dist(n,vector<int>(n,INT_MAX));
        priority_queue< pair<int,pair<int,int>> , vector<pair<int,pair<int,int>>>, greater<pair<int,pair<int,int>>>>pq;
        pq.push({0,{0,0}});
        dist[0][0]=grid[0][0];
        while(!pq.empty())
        {
            int cost=pq.top().first;
            int xcor=pq.top().second.first;
            int ycor=pq.top().second.second;
            pq.pop();
            for(int i=0;i<4;i++)
            {
                int xf=x[i]+xcor;
                int yf=y[i]+ycor;
                if(xf>=0 && xf<n && yf>=0 && yf<n)
                {
                    if(max(dist[xcor][ycor],grid[xf][yf]) < dist[xf][yf])
                    {

                    dist[xf][yf]=max(dist[xcor][ycor],grid[xf][yf]);
                    pq.push({dist[xf][yf],{xf,yf}});

                    }
                }
            }
            
        }
        return dist[n-1][n-1];
        
    }
};