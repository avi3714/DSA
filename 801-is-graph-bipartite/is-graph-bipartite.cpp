class Solution {
public:
bool dfs(int node,int color,vector<int>&colored,vector<vector<int>>&graph)
{
    colored[node]=color;
    for(int i=0;i<graph[node].size();i++)
    {
        if(colored[graph[node][i]]==-1)
        {
            if(dfs(graph[node][i],1-color,colored,graph)==false)
            return false;
        }
        else if(colored[graph[node][i]]==colored[node])
        return false;
    }
    return true;
}

    bool isBipartite(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<int>colored(n,-1);
        for(int i=0;i<n;i++)
        {
            if(colored[i]==-1)
            {
                if(dfs(i,0,colored,graph) == false)
                return false;
            }
        }
        return true;
    }
};