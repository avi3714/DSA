class Twitter {
public:
//ek map lunga jo unique id se uskka follower list dega
//phit ek timeline priority queue banunga,usme post dalunga mai,time ke saath.
map<int,set<int>>friends;
//friends[userid] mtlb wo kisko kisko follow krta hai.
map<int,vector<pair<int,int>>>posts;
//time,tweetid,deployerid
int curr;

    Twitter() {
        curr=0;
        friends.clear();
        
        
    }
    
    void postTweet(int userId, int tweetId) {
        posts[userId].push_back({curr++,tweetId});      
    }
    
    vector<int> getNewsFeed(int userId) {
        priority_queue<pair<int,int>>user;
        vector<int>ans;
        int n=0;
       vector<pair<int,int>>hispost=posts[userId];
       int size=hispost.size();
       for(int i=size-1;i>=max(0, size-10);i--)
        user.push({hispost[i].first,hispost[i].second});
        set<int>hisfriends=friends[userId];
        for(auto it:hisfriends)
        {
            vector<pair<int,int>>friendspost=posts[it];
           int size2=friendspost.size();
          for(int i=size2-1;i>=max(0,size2-10);i--)
           user.push({friendspost[i].first,friendspost[i].second});
        }
        while(n<10 && !user.empty())
        {
            int id=user.top().second;
            user.pop();
            ans.push_back(id);
            n++;
        }
        user=priority_queue<pair<int,int>>();
        return ans;
    }
    
    void follow(int followerId, int followeeId) {
        friends[followerId].insert(followeeId);
        
    }
    
    void unfollow(int followerId, int followeeId) {
        friends[followerId].erase(followeeId);
    }
};

/**
 * Your Twitter object will be instantiated and called as such:
 * Twitter* obj = new Twitter();
 * obj->postTweet(userId,tweetId);
 * vector<int> param_2 = obj->getNewsFeed(userId);
 * obj->follow(followerId,followeeId);
 * obj->unfollow(followerId,followeeId);
 */