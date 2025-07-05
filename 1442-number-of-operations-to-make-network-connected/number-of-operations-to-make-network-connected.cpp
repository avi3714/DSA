class disjoint_set{
vector<int>rank,parent;
public:
 disjoint_set(int n)
 {
    rank.resize(n+1,0);
    parent.resize(n+1);
    for(int i=0;i<=n;i++)
    {
        parent[i]=i;
    }
 }
 int findparent(int u)
 {
    if(parent[u]==u)
    return u;
    else
    return parent[u]=findparent(parent[u]);
 }
  void union_by_rank(int u,int v)
  {
    int ult_u=findparent(u);
    int ult_v=findparent(v);
    if(ult_u == ult_v)
    return;
    if(rank[ult_u] < rank[ult_v])
    {
        parent[ult_u]=ult_v;
    }
    else if(rank[ult_u] > rank[ult_v])
    {
        parent[ult_v]=ult_u;
    }
    else
    {
        rank[ult_v]++;
        parent[ult_u]=ult_v;
    }
  }
};
class Solution {
public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        if(n>connections.size()+1)
        return -1;
        int countextra=0;
        disjoint_set computer(n);
        for(int i=0;i<connections.size();i++)
        {
            if(computer.findparent(connections[i][0]) ==  computer.findparent(connections[i][1]))
            countextra++;
            else
            computer.union_by_rank(connections[i][0],connections[i][1]);
        }
        int count=0;
        for(int i=0;i<n;i++)
        {
            if(computer.findparent(i)==i)
            count++;
        }
       if(countextra>=count-1)
       return count-1;
       else
       return -1;

        
    }
};
//now  i will do using union by rank.