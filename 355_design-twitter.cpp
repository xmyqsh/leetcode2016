class Twitter {
public:
    /** Initialize your data structure here. */
    Twitter() {
        newsFeed.reserve(10);
        tweetCnts = 0;
    }
    
    /** Compose a new tweet. */
    void postTweet(int userId, int tweetId) {
        idToTweet[userId].push_back(make_pair(tweetCnts++, tweetId));
    }
    
    /** Retrieve the 10 most recent tweet ids in the user's news feed. Each item in the news feed must be posted by users who the user followed or by the user herself. Tweets must be ordered from most recent to least recent. */
    vector<int> getNewsFeed(int userId) {
        while (!pq.empty()) pq.pop();
        for (auto tweet : idToTweet[userId])
            pq.push(tweet);
        for (auto follower : idToFollower[userId])
            for (auto tweet : idToTweet[follower])
                pq.push(tweet);
        newsFeed.clear();
        while (!pq.empty() && newsFeed.size() < 10) newsFeed.push_back(pq.top().second), pq.pop();
        return newsFeed;
    }
    
    /** Follower follows a followee. If the operation is invalid, it should be a no-op. */
    void follow(int followerId, int followeeId) {
        if (followerId == followeeId) return;
        idToFollower[followerId].insert(followeeId);
    }
    
    /** Follower unfollows a followee. If the operation is invalid, it should be a no-op. */
    void unfollow(int followerId, int followeeId) {
        idToFollower[followerId].erase(followeeId);
    }
private:
    struct cmp {
        bool operator()(const pair<int, int>& p1, const pair<int, int>& p2) {
            return p1.first < p2.first;
        }
    };
    unordered_map<int, set<int> > idToFollower;
    unordered_map<int, vector<pair<int, int> > > idToTweet;
    priority_queue<pair<int, int>, vector<pair<int, int> >, cmp > pq;
    vector<int> newsFeed;
    int tweetCnts;
};

/**
 * Your Twitter object will be instantiated and called as such:
 * Twitter obj = new Twitter();
 * obj.postTweet(userId,tweetId);
 * vector<int> param_2 = obj.getNewsFeed(userId);
 * obj.follow(followerId,followeeId);
 * obj.unfollow(followerId,followeeId);
 */
