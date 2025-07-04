class Solution {
  public:
  bool dfs(int node,vector<int>&parent,vector<int>&visited,vector<vector<int>>&adj)
  {
      visited[node]=1;
      for(int i=0;i<adj[node].size();i++)
      {
          if(visited[adj[node][i]]==1 && parent[node]!=adj[node][i])
          return true;
          else if(visited[adj[node][i]]==0)
          {
              parent[adj[node][i]]=node;
             if(dfs(adj[node][i],parent,visited,adj))
             return true;
          }
      }
      return false;
  }
    bool isCycle(int V, vector<vector<int>>& edges) {
        // Code here
        vector<vector<int>>adj(V);
        for(int i=0;i<edges.size();i++)
        {
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
           
        }
        vector<int>visited(V,0),parent(V,-1);
        for(int i=0;i<V;i++)
        {
            if(visited[i]==0)
            {
                if(dfs(i,parent,visited,adj))
                return true;
            }
        }
        return false;
        
            
            
        
    }
};