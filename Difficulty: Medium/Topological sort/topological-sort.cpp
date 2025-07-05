class Solution {
  public:
  void dfs(int index,stack<int>&st,vector<vector<int>>&adj,vector<int>&visited)
  {
      visited[index]=1;
      for(int i=0;i<adj[index].size();i++)
      {
          if(visited[adj[index][i]]==0)
          {
              dfs(adj[index][i],st,adj,visited);
          }
      }
      st.push(index);
  }
    vector<int> topoSort(int V, vector<vector<int>>& edges) {
        // code here
        vector<int>visited(V,0);
        stack<int>st;
        vector<vector<int>>adj(V);
        for(int i=0;i<edges.size();i++)
        {
            adj[edges[i][0]].push_back(edges[i][1]);
        }
        for(int i=0;i<V;i++)
        {
            if(visited[i]==0)
            {
                dfs(i,st,adj,visited);
            }
        }
        vector<int>answer;
        while(!st.empty())
        {
            answer.push_back(st.top());
            st.pop();
        }
        return answer;
    }
};