class Solution {
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        vector<int> dp(days.size() + 1, INT_MAX);
        dp[0] = 0;
        for (int i = 0; i != days.size(); ++i) {
            // 1-day
            dp[i + 1] = min(dp[i + 1], dp[i] + costs[0]);
            // 7-day
            for (int j = i; j != days.size() && days[j] < days[i] + 7; ++j)
                dp[j + 1] = min(dp[j + 1], dp[i] + costs[1]);
            // 30-day
            for (int j = i; j != days.size() && days[j] < days[i] + 30; ++j)
                dp[j + 1] = min(dp[j + 1], dp[i] + costs[2]);
        }
        return dp[days.size()];
    }
};
