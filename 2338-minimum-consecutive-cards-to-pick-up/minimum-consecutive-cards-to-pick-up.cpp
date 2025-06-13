class Solution {
public:
    int minimumCardPickup(vector<int>& cards) {
        map<int,int>mpp;
        int n=cards.size();
        int i=0;
        int mini=INT_MAX;
        for(auto it:cards)
        {
            if(mpp.find(it)!=mpp.end())
            {
                mini=min(mini,i-mpp[it]+1);
            }
            mpp[it]=i;
            i++;
        }
        if(mini==INT_MAX)
        return -1;
        else
        return mini;
        
    }
};