class Solution {
public:
int x[4]={0,0,1,-1};
int y[4]={1,-1,0,0};
bool isValid(int x,int y,int m,int n)
{
    if(x>=0 && x<m && y>=0 && y<n)
    return true;
    else
    return false;
}
int bfs(vector<vector<int>>& grid,vector<vector<int>>& visited,int m,int n)
{
    int count=0;
    queue<pair<int,int>>q;
    //q will store xi,yi of rotten oranges
    //inital rotten oranges to be put in the queue
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(grid[i][j]==2)
            {
            q.push({i,j});
             visited[i][j]=1;
            }
        }
    }
    if(q.empty())
    return 0;
    while(!q.empty())
    {
    
        int que_size=q.size();
        cout<<que_size<<endl;
        for(int size=0;size<que_size;size++)
        {
        pair<int,int>affected=q.front();
        q.pop();
        for(int i=0;i<4;i++)
        {
            int xcor=x[i]+affected.first;
            int ycor=y[i]+affected.second;
            if(isValid(xcor,ycor,m,n))
            {
                if(grid[xcor][ycor]==1 && visited[xcor][ycor]==0)
                {
                    q.push({xcor,ycor});
                    visited[xcor][ycor]=1;
                    grid[xcor][ycor]=2;
                }
            }
        }
        }
            count++;

        
    }
    return count-1;
}
    int orangesRotting(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        vector<vector<int>>visited(m,vector<int>(n,0));
        int ans=bfs(grid,visited,m,n);
        for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(grid[i][j]==1)
            {
           return -1;
            }
        }
    }
        return ans;
        
    }
};