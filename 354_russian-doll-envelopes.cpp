class Solution {
public:
    int maxEnvelopes(vector<pair<int, int>>& envelopes) {
        if (envelopes.size() < 2) return envelopes.size();
        sort(envelopes.begin(), envelopes.end());
        vector<int> dp(envelopes.size(), 1);
        int ret = 1;
        for (int i = 0; i != envelopes.size(); ++i) {
            for (int j = i - 1; j >= 0; --j)
                if (envelopes[i].first > envelopes[j].first && envelopes[i].second > envelopes[j].second && dp[i] < dp[j] + 1)
                    dp[i] = dp[j] + 1;
            ret = max(ret, dp[i]);
        }
        return ret;
    }
};

class Solution {
public:
    int maxEnvelopes(vector<pair<int, int>>& envelopes) {
        if (envelopes.size() < 2) return envelopes.size();
        sort(envelopes.begin(), envelopes.end(), [](const pair<int, int>& p1, const pair<int, int>& p2) {
            return p1.first < p2.first || p1.first == p2.first && p1.second > p2.second;
        });
        vector<int> tail;
        tail.reserve(envelopes.size());
        for (auto envelope : envelopes) {
            auto iter = lower_bound(tail.begin(), tail.end(), envelope.second);
            if (iter == tail.end()) tail.push_back(envelope.second);
            else *iter = envelope.second;
        }
        return tail.size();
    }
};
