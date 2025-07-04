class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        if(beginWord==endWord)
        return 0;
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
            for(int i=0;i<wordList.size();i++)
            {
                string s=wordList[i];
                if(visited[i]==1)
                continue;
                //now check wheteher string s and s1 have one difference or not.
                if(s.length()!=s1.length()||s1==s)
                continue;
                int count=0;int flag=0;
                for(int k=0;k<s.length();k++)
                {
                    if(s[k]==s1[k])
                    continue;
                    else if(count==0)
                    {
                        count++;
                    }
                    else
                    {
                        count++;break;
                    }
                }
                if(count==1)
                {
                    q.push({cost+1,s});
                    visited[i]=1;
                }
            }
        }
        return 0;
    }
};