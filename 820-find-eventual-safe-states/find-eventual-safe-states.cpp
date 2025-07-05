class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<int>outdegree(n,0);
        for(int i=0;i<n;i++)
        {
            outdegree[i]=graph[i].size();

        }
        vector<vector<int>>out(n);
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<graph[i].size();j++)
            {
                out[graph[i][j]].push_back(i);
            }
        }
        queue<int>q;
        for(int i=0;i<n;i++)
        {
            if(outdegree[i]==0)
            q.push(i);
        }
        vector<int>answer;
        while(!q.empty())
        {
            int r=q.front();
            q.pop();
            answer.push_back(r);
            for(int i=0;i<out[r].size();i++)
            {
                outdegree[out[r][i]]--;
                if(outdegree[out[r][i]] == 0)
                q.push(out[r][i]);
            }

        }
        sort(answer.begin(),answer.end());
        return answer;
    }
};
//terminal nnode means indegree = 0 
//all terminal nodes are safe nodes.