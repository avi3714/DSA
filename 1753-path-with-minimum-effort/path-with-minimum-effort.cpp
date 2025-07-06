class Solution {
public:
int x[4]={0,0,-1,1};
int y[4]={1,-1,0,0};
    int minimumEffortPath(vector<vector<int>>& heights) {
        int rows=heights.size();
        int columns=heights[0].size();
        priority_queue< pair<int,pair<int,int>> ,vector<pair<int,pair<int,int>>>, greater<pair<int,pair<int,int>> > >pq;
        pq.push({0,{0,0}});
        vector<vector<int>>dist(rows,vector<int>(columns,INT_MAX));
        dist[0][0]=0;
        while(!pq.empty())
        {
            pair<int, pair<int,int>> r=pq.top();
            int cost=r.first;
            int xcor=r.second.first;
            int ycor=r.second.second;
            pq.pop();
            if(xcor==rows-1 && ycor==columns-1)
            break;
            for(int i=0;i<4;i++)
            {
                int final_x=xcor+x[i];
                int final_y=ycor+y[i];
                if(final_x>=0 && final_x <rows && final_y>=0 && final_y < columns)
                {
                    if(dist[final_x][final_y] > max(abs(heights[final_x][final_y]-heights[xcor][ycor]),dist[xcor][ycor]))
                    {
                        dist[final_x][final_y]=max(abs(heights[final_x][final_y]-heights[xcor][ycor]),dist[xcor][ycor]);
                        pq.push({dist[final_x][final_y],{final_x,final_y}});
                    }
                }
            }
        }
        return dist[rows-1][columns-1];
        
    }
};