class DSU{
    vector<int>parent,size;
 public:
 DSU(int n)
 {
    parent.resize(n+1);
    size.resize(n+1,1);
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
 void union_by_size(int u,int v)
 {
    int ult_u=findparent(u);
    int ult_v=findparent(v);
    if(ult_u == ult_v)
    return;
    if(size[ult_u] < size[ult_v])
    {
        size[ult_v]+=size[ult_u];
        parent[ult_u]=ult_v;
    }
    else if(size[ult_u] > size[ult_v])
    {
        size[ult_u]+=size[ult_v];
        parent[ult_v]=ult_u;
    }
    else
    {
        size[ult_u]+=size[ult_v];
        parent[ult_v]=ult_u;
    }
 }
 int evaluate()
 {
    int ans=0;
    for(int i=0;i<parent.size()-1;i++)
    {
        
        if(parent[i]==i && size[i]!=1)
        ans++;
    }
    return ans;
 }

 
};
class Solution {
public:
    int removeStones(vector<vector<int>>& stones) {
        int row=0,column=0;
        for(int i=0;i<stones.size();i++)
        {
            row=max(row,stones[i][0]);
            column=max(column,stones[i][1]);
        }
        row++;
        column++;
        DSU stone(row+column);
        for(int i=0;i<stones.size();i++)
        {
            int a=stones[i][0];
            int b=stones[i][1]+row;
            if(stone.findparent(a)==stone.findparent(b))
            continue;
            else
            stone.union_by_size(a,b);
        }
        return stones.size()-stone.evaluate();
    }
};