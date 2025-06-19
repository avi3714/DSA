class Solution {
  public:
    vector<int> maxCombinations(int N, int K, vector<int> &A, vector<int> &B) {
        // code here
        sort(A.begin(),A.end(),greater<int>());
        sort(B.begin(),B.end(),greater<int>());
        priority_queue<pair<int,pair<int,int>>>q;
        q.push({A[0]+B[0],{0,0}});
        vector<int>ans;
        set<pair<int,int>>st;
        st.insert({0,0});
        int n=N;
        while(K--)
        {
            pair<int,pair<int,int>>p=q.top();
            q.pop();
            int i=p.second.first;
            int j=p.second.second;
            ans.push_back(p.first);
            if(st.find({i,i})==st.end())
            {
                st.insert({i,i});
            q.push({A[i]+B[i],{i,i}});
            }
             if(st.find({j,j})==st.end())
             {
            q.push({A[j]+B[j],{j,j}});
            st.insert({j,j});
                 
             }
            if(i+1<n && st.find({i+1,j})==st.end())
            {
            q.push({A[i+1]+B[j],{i+1,j}});
            st.insert({i+1,j});
                
            }
            if(j+1<n && st.find({i,j+1})==st.end())
            {
            q.push({A[i]+B[j+1],{i,j+1}});
            st.insert({i,j+1});
                
            }
            
            
        }
        return ans;
        
    }
};