class Twitter {
public:
    unordered_map<int, int> tickTweetMap;
    unordered_map<int, priority_queue<int>> userTweetHeapMap;
    unordered_map<int, unordered_set<int>> userFollowsMap;
    int ticks = 0;
    
    Twitter() {
        
    }
    
    void postTweet(int userId, int tweetId)
    {
        tickTweetMap[ticks] = tweetId;
        userTweetHeapMap[userId].push(ticks);
        ticks++;
    }
    
    vector<int> getNewsFeed(int userId)
    {
        priority_queue<int> maxHeap;

        int count = 0;
        auto temp = userTweetHeapMap[userId];
        while (count < 10 && !temp.empty())
        {
            maxHeap.push(temp.top());
            temp.pop();
            count++;
        }

        for (const int& followee : userFollowsMap[userId])
        {
            count = 0;
            auto temp1 = userTweetHeapMap[followee];
            while (count < 10 && !temp1.empty())
            {
                maxHeap.push(temp1.top());
                temp1.pop();
                count++;
            }
        }

        vector<int> response;

        count = 0;
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