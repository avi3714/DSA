class Solution {
public:
    bool isAnagram(string s, string t) {
        map<char,int>mpp1;
        map<char,int>mpp2;
        if(s.length()!=t.length())
        return false;
        int n=s.length();
        for(int i=0;i<n;i++)
        {
            mpp1[s[i]]++;
            mpp2[t[i]]++;
        }
        for(int i=0;i<n;i++)
        {
            if(mpp1[s[i]]!=mpp2[s[i]])
            return false;
        }
        return true;
    }
};