class Solution {
public:
void bfs(int index,vector<int>& visited,vector<vector<int>>& isConnected)
{
    queue<int>q;
    q.push(index);
    visited[index]=1;
    while(!q.empty())
    {
        int i=q.front();
        q.pop();
        for(int j=0;j<isConnected.size();j++)
        {
            if(visited[j]==0 && isConnected[i][j]==1)
            {
                q.push(j);
                visited[j]=1;
            }
        }
    }
}
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n=isConnected.size();
        vector<int>visited(n,0);
        int count=0;
        for(int i=0;i<n;i++)
        {
            if(visited[i]==1)
            continue;
            else
            {
                count++;
                bfs(i,visited,isConnected);
            }
        }
        return count;
    }
};