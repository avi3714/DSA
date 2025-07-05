class Solution {
  public:
  bool dfs(int index,vector<int>&visited,vector<int>&path_visited,vector<vector<int>>&adj)
  {
      visited[index]=1;
      path_visited[index]=1;
      for(int i=0;i<adj[index].size();i++)
      {
          if(visited[adj[index][i]]==0)
          {
              if(dfs(adj[index][i],visited,path_visited,adj))
              return true;
          }
          else if(path_visited[adj[index][i]]==1)
          return true;
      }
      path_visited[index]=0;
      return false;
  }
    bool isCyclic(int V, vector<vector<int>> &edges) {
        // code here
        vector<int>visited(V,0);
        vector<int>path_visited(V,0);
        vector<vector<int>>adj(V);
        for(int i=0;i<edges.size();i++)
        {
            adj[edges[i][0]].push_back(edges[i][1]);
        }
        for(int i=0;i<V;i++)
        {
            if(visited[i]==0)
            {
                if(dfs(i,visited,path_visited,adj))
                return true;
            }
        }
        return false;
    }
};