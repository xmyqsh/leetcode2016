class Solution {
public:
    int countSubstrings(string s) {
        vector<vector<int> > dp(s.size(), vector<int>(s.size(), 0));
        for (int i = 0; i != s.size(); ++i) dp[i][i] = 1;
        int ret = s.size();
        for (int len = 2; len <= s.size(); ++len) {
            for (int b = 0, e = b + len - 1; e < s.size(); ++b, ++e) {
                dp[b][e] = s[b] == s[e] ? (len == 2 ? 1 : dp[b + 1][e - 1]) : 0;
                ret += dp[b][e];
            }
        }
        return ret;
    }
};
