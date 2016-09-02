class Solution {
public:
    int maximumGap(vector<int>& num) {
        if (num.size() < 2) return 0;
        int maxVal = num[0], minVal = num[0];
        for (int i = 1; i < num.size(); ++i) {
            maxVal = max(maxVal, num[i]);
            minVal = min(minVal, num[i]);
        }
        if (maxVal == minVal) return 0;
        const int bucketGap = ceil((double)(maxVal - minVal) / (num.size() / 2));
        const int bucketSize =  ceil((double)(maxVal - minVal) / bucketGap);
        vector<pair<int, int> > buckets(bucketSize, make_pair(INT_MAX, INT_MIN));
        for (auto n : num) {
            if (n == minVal || n == maxVal) continue;
            const int idx = (n - minVal) / bucketGap;
            buckets[idx].first = min(buckets[idx].first, n);
            buckets[idx].second = max(buckets[idx].second, n);
        }
        int maxGap = 0, lastMax = minVal;
        for (auto bucket : buckets) {
            if (bucket.first == INT_MAX) continue;
            maxGap = max(maxGap, bucket.first - lastMax);
            lastMax = bucket.second;
        }
        return max(maxGap, maxVal - lastMax);
    }
};
