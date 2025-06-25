class Solution {
public:
class compare{
public :
bool operator()(const string &s1,const string &s2)
{
return s1.length()<s2.length();
}
};

bool canbe(string s1,string s2)
{
    

    if(s1.length() - s2.length() != 1) return false; // ✅ minimal safety check

    int count=0,ind1=0;
    for(int ind=0;ind<s1.length();ind++)
    {
       if(ind1 < s2.length() && s1[ind]==s2[ind1]) // ✅ prevent out-of-bounds
       {
        ind1++;
        continue;
       }
       else if(count==0){
       count++;}
       else
       return false;
    }

    return ind1 == s2.length(); // ✅ ensures all of s2 was matched
}

int longestStrChain(vector<string>& words) {
    int n=words.size();
    sort(words.begin(),words.end(),compare());
    vector<int>dp(n,1);
  //  cout<<canbe(2,3,words)<<endl;
    int maxi=1;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<i;j++)
        {
            if(words[i].length()-words[j].length()==1 && canbe(words[i],words[j]))
            {
                dp[i]=max(dp[i],1+dp[j]);
            }
        }
        maxi=max(maxi,dp[i]);
    }
    return maxi;
}
};
