class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        if(beginWord==endWord)
        return 0;
        set<string>st;
        map<string,int>mpp;
        for(int i=0;i<wordList.size();i++)
        st.insert(wordList[i]);
        vector<int>visited(wordList.size(),0);
        queue<pair<int,string>>q;
        q.push({0,beginWord});
        while(!q.empty())
        {
            pair<int,string>r=q.front();
            q.pop();
            string s1=r.second;
            int cost=r.first;
            if(s1==endWord)
            return cost+1;
            string hy=s1;
            for(int i=0;i<s1.length();i++)
            {           
            for(int j=0;j<26;j++)
            {
                s1[i]='a'+j;
                if( st.find(s1)!=st.end())
                {
                     q.push({cost+1,s1});
                     auto it=st.find(s1);
                     st.erase(it);
                }
            }
            s1=hy;
            }
           
        }
        return 0;
    }
};