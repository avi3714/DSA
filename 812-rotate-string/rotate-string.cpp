class Solution {
public:
    bool rotateString(string s, string goal) {
        string ss=s+s;
        if(s.length()!=goal.length())
        return false;
        int a=ss.find(goal);
        if(a<ss.length())
        return true;
        else
       return false;
    }
};