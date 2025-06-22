class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        int children=g.size();
        int cookie=s.size();
        sort(g.begin(),g.end());
        sort(s.begin(),s.end());
        int j=0;
        int count=0;
        for(int i=0;i<cookie;i++)
        {
           while(j<children)
           {
            if(g[j]<=s[i])
            {
                count++;
                j++;
                break;
            }
            else
            break;
           } 
        }
        return count;
        
    }
};