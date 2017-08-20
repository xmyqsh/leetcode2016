class Solution {
public:
    int strangePrinter(string s) {
        if (s.size() < 2) return s.size();
        vector<vector<int> > mp(256);
        for (int i = 0; i != s.size(); ++i) {
            mp[s[i]].push_back(i);
        }
        vector<vector<int> > dp(s.size(), vector<int>(s.size(), 0));
        for (int i = 0; i != s.size(); ++i) dp[i][i] = 1;
        for (int k = 2; k <= s.size(); ++k) {
            for (int i = 0, j = i + k - 1; j != s.size(); ++i, ++j) {
                dp[i][j] = dp[i][j - 1] + 1;
                for (auto prePos : mp[s[j]]) {
                    if (prePos < i) continue;
                    if (prePos >= j) break;
                    dp[i][j] = min(dp[i][j], dp[i][prePos] + dp[prePos + 1][j - 1]);
                }
            }
        }
        return dp[0][s.size() - 1];
    }
};
