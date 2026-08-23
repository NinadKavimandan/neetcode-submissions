class Twitter {
public:
    unordered_map<int, int> tickTweetMap;
    unordered_map<int, vector<int>> userTweetMap;
    unordered_map<int, unordered_set<int>> userFollowsMap;
    int ticks = 0;
    
    Twitter() {
        
    }
    
    void postTweet(int userId, int tweetId)
    {
        tickTweetMap[ticks] = tweetId;
        userTweetMap[userId].push_back(ticks);
        ticks++;
    }
    
    vector<int> getNewsFeed(int userId)
    {
        priority_queue<int> maxHeap;

        int totalUserTweets = userTweetMap[userId].size();
        for (int i=totalUserTweets - 1;i > max(-1, totalUserTweets - 11);i--)
        {
            maxHeap.push(userTweetMap[userId][i]);
        }

        for (const int& followee : userFollowsMap[userId])
        {
            int totalFolloweeTweets = userTweetMap[followee].size();
            for (int i=totalFolloweeTweets - 1;i > max(-1, totalFolloweeTweets - 11);i--)
            {
                maxHeap.push(userTweetMap[followee][i]);
            }
        }

        vector<int> response;

        int count = 0;
        while (count < 10 && !maxHeap.empty())
        {
            response.push_back(tickTweetMap[maxHeap.top()]);
            maxHeap.pop();
            count++;
        }

        return response;
    }
    
    void follow(int followerId, int followeeId)
    {
        userFollowsMap[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId)
    {
        userFollowsMap[followerId].erase(followeeId);
    }
};

/*

since we want most recent 10, use a max heap
maintain tick vs tweet map for recency in case tweetIds are out of order
maintain users own tweets into the newsfeed heap

handle news feed on follows and unfollows lazily, during getNewsFeed call, take top 10 tweets from self and each followee, discard whatever does not being to someone we follow

*/