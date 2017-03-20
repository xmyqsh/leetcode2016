class Solution {
public:
    int findPoisonedDuration(vector<int>& timeSeries, int duration) {
        if (timeSeries.empty()) return 0;
        int ret = duration;
        for (int i = 1; i != timeSeries.size(); ++i)
            ret += min(timeSeries[i] - timeSeries[i - 1], duration);
        return ret;
    }
};
