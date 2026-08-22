class Twitter {
public:
    unordered_map<int, int> tickTweetMap;
    unordered_map<int, priority_queue<int>> userTweetHeapMap;
    unordered_map<int, unordered_set<int>> userFollowersMap;
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
        vector<int> temp1;
        while (count < 10 && !userTweetHeapMap[userId].empty())
        {
            temp1.push_back(userTweetHeapMap[userId].top());
            maxHeap.push(userTweetHeapMap[userId].top());
            userTweetHeapMap[userId].pop();
            count++;
        }

        for (int& t : temp1)
        {
            userTweetHeapMap[userId].push(t);
        }

        for (const int& followee : userFollowsMap[userId])
        {
            count = 0;
            vector<int> temp;
            while (count < 10 && !userTweetHeapMap[followee].empty())
            {
                temp.push_back(userTweetHeapMap[followee].top());
                maxHeap.push(userTweetHeapMap[followee].top());
                userTweetHeapMap[followee].pop();
                count++;
            }

            for (int& t : temp)
            {
                userTweetHeapMap[followee].push(t);
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
        userFollowersMap[followeeId].insert(followerId);
        userFollowsMap[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId)
    {
        userFollowersMap[followeeId].erase(followerId);
        userFollowsMap[followerId].erase(followeeId);
    }
};

/*

since we want most recent 10, use a max heap
maintain a mapping of tweet to id in a map,
maintain users own tweets and followings tweets into the newsfeed heap

handle news feed on follows and unfollows lazily, during getNewsFeed call, take top 10 tweets from self and each followee, discard whatever does not being to someone we follow

*/