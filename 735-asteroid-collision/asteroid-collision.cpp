class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        int n=asteroids.size();
        stack<pair<int,int>>st;
        vector<int>ans;
        for(int i=0;i<n;i++)
        {
            if(asteroids[i]>0)
            {
                st.push({asteroids[i],i});
                continue;
            }
            while(!st.empty()&&st.top().first<(-1*asteroids[i]))
            {
               st.pop();
            }
            if(!st.empty()&& st.top().first+asteroids[i]==0)
            {
                st.pop();
                continue;
            }
            if(st.empty())
            ans.push_back(i);
        }
        while(!st.empty())
        {
            ans.push_back({st.top().second});
            st.pop();
        }
        sort(ans.begin(),ans.end());
        vector<int>answer;
        for(int i=0;i<ans.size();i++)
        {
            answer.push_back(asteroids[ans[i]]);
        }
        return answer;
    }
};