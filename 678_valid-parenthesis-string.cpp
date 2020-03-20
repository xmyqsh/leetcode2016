class Solution {
public:
    bool checkValidString(string s) {
        vector<unordered_set<int>> dp(s.size() + 1);
        dp[0].insert(0);
        for (int i = 0; i != s.size(); ++i) {
            for (auto cur : dp[i]) {
                if (s[i] == '(') dp[i + 1].insert(cur + 1);
                else if (s[i] == ')') {
                    if (cur != 0) dp[i + 1].insert(cur - 1);
                } else {
                    dp[i + 1].insert(cur + 1);
                    dp[i + 1].insert(cur);
                    if (cur != 0) dp[i + 1].insert(cur - 1);
                }
            }
        }
        return dp[s.size()].count(0);
    }
};
