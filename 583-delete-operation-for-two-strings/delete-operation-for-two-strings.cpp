class Solution {
public:
int longestcommonsubsequence(string s1,string s2)
{
    int n1=s1.length();
    int n2=s2.length();
    vector<int>prev(n2+1,0),curr(n2+1,0);
   for(int i=1;i<=n1;i++)
   {
    for(int j=1;j<=n2;j++)
    {
        if(s1[i-1]==s2[j-1])
        curr[j]=prev[j-1]+1;
        else
        curr[j]=max(prev[j],curr[j-1]);
    }
    prev=curr;
   }
   return prev[n2];
}
    int minDistance(string word1, string word2) {
        int r=longestcommonsubsequence(word1,word2);
        int n1=word1.size();
        int n2=word2.size();
        return n1+n2-r*2;
        
    }
};