class Solution {
public:
int x[4]={0,0,1,-1};
int y[4]={1,-1,0,0};
vector<vector<int>> bfs(vector<vector<int>>& mat,vector<vector<int>>& visited,int m,int n)
{   
    priority_queue< pair<int, pair<int,int>>, vector<pair<int, pair<int,int>>> ,      greater< pair<int, pair<int,int>> >>q;
    vector<vector<int>>cost(m,vector<int>(n,0));
    for(int i=0;i<m;i++ )
    {
        for(int j=0;j<n;j++)
        {
            if(mat[i][j]==0)
            {
                q.push({0,{i,j}});
                visited[i][j]=1;
                cost[i][j]=0;
            }
        }
    }
    while(!q.empty())
    {
        pair<int, pair<int,int>> r=q.top();
        q.pop();
        for(int i=0;i<4;i++)
        {
            int xcor=x[i]+r.second.first;
            int ycor=y[i]+r.second.second;
            if(xcor>=0 && xcor<m && ycor >=0 && ycor <n)
            {
                if(visited[xcor][ycor]==0)
                {
                    cost[xcor][ycor]=r.first+1;
                    visited[xcor][ycor]=1;
                    q.push({r.first+1,{xcor,ycor}});
                }
            }
        }
        
    }
    return cost;
}
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m=mat.size();
        int n=mat[0].size();
        vector<vector<int>>visited(m,vector<int>(n,0));
       return  bfs(mat,visited,m,n);
    }
};