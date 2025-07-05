class Solution {
  public:
    bool isCyclic(int V, vector<vector<int>> &edges) {
        // code here
        vector<vector<int>>adj(V);
        vector<int>indegree(V,0);
        for(int i=0;i<edges.size();i++)
        {
            adj[edges[i][0]].push_back(edges[i][1]);
            indegree[edges[i][1]]++;
        }
        queue<int>q;
        for(int i=0;i<V;i++)
        {
            
            if(indegree[i]==0)
            q.push(i);
        }
        int count=0;
        while(!q.empty())
        {
            int r=q.front();
            q.pop();
            count++;
            for(int i=0;i<adj[r].size();i++)
            {
                indegree[adj[r][i]]--;
                if(indegree[adj[r][i]] == 0)
                q.push(adj[r][i]);
            }
        }
        if(count < V)
        return true;
        else
        return false;
    }
};