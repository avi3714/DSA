class Solution {
public:
void dfs(int index,vector<int>&visited,vector<vector<int>>&adj)
{
    visited[index]=1;
    for(int i=0;i<adj[index].size();i++)
    {
        if(visited[adj[index][i]] == 0)
        dfs(adj[index][i],visited,adj);
    }
}
    int makeConnected(int n, vector<vector<int>>& connections) {
        if(n>connections.size()+1)
        return -1;
        vector<int>visited(n,0);
        vector<vector<int>>adj(n);
        for(int i=0;i<connections.size();i++)
        {
            adj[connections[i][0]].push_back(connections[i][1]);
            adj[connections[i][1]].push_back(connections[i][0]);
        }
        int count=0;
        for(int i=0;i<n;i++)
        {
            if(visited[i]==0)
            {
                count++;
                dfs(i,visited,adj);
            }
        }
        
        return count-1;

        
    }
};
//so basically i have to find number of connected compoents.??