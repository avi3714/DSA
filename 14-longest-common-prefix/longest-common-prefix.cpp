class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int n=strs.size();
        int n1=strs[0].length();
        string s4=strs[0];
        int flag=0;string answer;
        for(int i=0;i<n1;i++)
        {
            for(int j=1;j<n;j++)
            {
                string s=strs[j];
                if(i>s.length()){
                flag=1;
                break;}
                if(s[i]!=s4[i])
                {
                    flag=1;break;
                }

            }
            if(flag==0)
            answer.push_back(s4[i]);
        }
        return answer;
    }
};