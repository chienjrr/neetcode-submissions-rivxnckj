class Twitter {
private:
    struct Tweet{
        int id;
        int time;
        Tweet* next;
        Tweet(int i, int t): id(i), time(t), next(nullptr){}
    };

    int timestamp = 0;
    unordered_map<int, unordered_set<int>> following;
    unordered_map<int, Tweet*> userTweets;


public:
    
    void postTweet(int userId, int tweetId) {
        Tweet* newTweet = new Tweet(tweetId, timestamp++);
        newTweet->next = userTweets[userId];
        userTweets[userId] = newTweet;
    }
    
    vector<int> getNewsFeed(int userId) {
        auto compare = [](Tweet* a, Tweet* b) {return a->time < b->time;};
        priority_queue<Tweet*, vector<Tweet*>, decltype(compare) > pq(compare);
        if(userTweets.count(userId) && userTweets[userId]){
            pq.push(userTweets[userId]);
        }
        for(int followeeId : following[userId]){
            if(userTweets.count(followeeId) && userTweets[followeeId]){
                pq.push(userTweets[followeeId]);
            }
        }
        vector<int> res;
        int count = 0;
        while(!pq.empty() && count < 10){
            Tweet* curr = pq.top();
            pq.pop();
            
            res.push_back(curr->id);
            count++;
            if(curr->next) pq.push(curr->next);
        }
        return res;
    }
    
    void follow(int followerId, int followeeId) {
        if(followerId != followeeId){
            following[followerId].insert(followeeId);
        }
    }
    
    void unfollow(int followerId, int followeeId) {
        following[followerId].erase(followeeId);
    }
};
