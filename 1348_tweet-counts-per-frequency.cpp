class TweetCounts {
public:
    TweetCounts() {
        
    }
    
    void recordTweet(string tweetName, int time) {
        ++mp[time][tweetName];
    }
    
    vector<int> getTweetCountsPerFrequency(string freq, string tweetName, int startTime, int endTime) {
        vector<int> result;
        int period = freq == "minute" ? 60 : freq == "hour" ? 3600 : 3600 * 24;
        int b = startTime, e = min(startTime + period - 1, endTime);
        auto iter = mp.begin();
        while (iter != mp.end() && iter->first < b) ++iter;
        while (b <= endTime) {
            int cnt = 0;
            while (iter != mp.end() && iter->first <= e) {
                cnt += iter->second[tweetName];
                ++iter;
            }
            result.push_back(cnt);
            b = e + 1;
            e = min(b + period - 1, endTime);
        }
        return result;
    }
private:
    map<int, unordered_map<string, int>> mp;
};

/**
 * Your TweetCounts object will be instantiated and called as such:
 * TweetCounts* obj = new TweetCounts();
 * obj->recordTweet(tweetName,time);
 * vector<int> param_2 = obj->getTweetCountsPerFrequency(freq,tweetName,startTime,endTime);
 */
