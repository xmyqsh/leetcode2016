class Solution {
public:
    int numDistinct(string s, string t) {
        vector<int> dp(t.size(), 0);
        for (int i = 0; i < s.size(); ++i) {
            int last = 1;
            for (int j = 0; j < t.size(); ++j) {
                int tmp = dp[j];
                dp[j] += s[i] == t[j] ? last : 0;
                last = tmp;
            }
        }
        return dp[t.size() - 1];
    }
};
