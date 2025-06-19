class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        int size=tasks.size();
        priority_queue<pair<int,int>>pq;
        queue<pair<int,int>>q;
        vector<int>freq(26,0);
        for(int i=0;i<size;i++)
        freq[tasks[i]-'A']++;
        for(int i=0;i<26;i++)
        {
            if(freq[i]>0)
        pq.push({freq[i],0});
        }
        int time=0;
        while(!pq.empty() || !q.empty())
        {
            while(!q.empty() && q.front().second ==time)
            {
                pair<int,int> po=q.front();
            pq.push(po);
            q.pop();
            }
            if(!pq.empty())
            {
                int frequency=pq.top().first;
                int tym=pq.top().second;
                pq.pop();
                if(frequency>1)
                q.push({frequency-1,time+n+1});
            }
            time++;
        }
        return time;
        
    }
};