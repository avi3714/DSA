vector<int> Smallestonleft(int arr[], int n) {
    // Complete the function
    set<int>s;
    vector<int>ans(n,-1);
    for(int i=0;i<n;i++)
    {
        s.insert(arr[i]);
        if(s.find(arr[i])==s.begin())
        continue;
        
        auto itr=s.find(arr[i]);
        itr--;
        ans[i]=*itr;
    }
    return ans;
}