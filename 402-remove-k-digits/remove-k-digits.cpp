class Solution {
public:
    string removeKdigits(string num, int k) {
        int n=num.length();
        stack<int>st;
        for(int i=0;i<n;i++)
        {
            while(!st.empty()&& k>0&&st.top()>(num[i]-'0'))
            {
                st.pop();
                k--;
            }
            st.push(num[i]-'0');
        }
        while(k>0)
        {
            st.pop();
            k--;
        }
        if(st.empty())
        return "0";
        string s1="";
        while(!st.empty())
        {
            char ch=st.top()+'0';
            s1.push_back(ch);
            st.pop();
        }
        
        while(s1.length()!=0&&s1.back()=='0')
        s1.pop_back();
        reverse(s1.begin(),s1.end());
        if(s1=="")
        return "0";
        return s1;
    }
};