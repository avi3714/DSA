class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        multiset<int>st;
        int n=hand.size();
        for(int i=0;i<n;i++)
        {
            st.insert(hand[i]);
        }
        cout<<st.size()<<endl;
        if(n%groupSize !=0)
        return false;
        for(int i=0;i<n/groupSize;i++)
        {
          auto it=st.begin();
           for(int j=1;j<groupSize;j++)
           {
            auto it2=st.find((*it)+j);
            if(it2==st.end())
            return false;
            else
            st.erase(it2);
           }
           st.erase(it);
        }
        if(st.empty())
        return true;
        else
        return false;
    }
};