class Solution {
public:
    bool isScramble(string s1, string s2) {
        if (s1.size() != s2.size()) return false;
        if (s1.empty()) return true;
        if (s1.size() == 1) return s1[0] == s2[0];
        vector<vector<vector<bool> > > dp(s1.size(), vector<vector<bool> >(s1.size(), vector<bool>(s1.size() + 1, false)));
        for (int i = s1.size() - 1; i >= 0; --i) {
            for (int j = s2.size() - 1; j >= 0; --j) {
                dp[i][j][1] = s1[i] == s2[j];
                for (int l = 2; i + l <= s1.size() && j + l <= s2.size(); ++l) {
                    for (int n = 1; n < l && !dp[i][j][l]; ++n) {
                        dp[i][j][l] = dp[i][j][l] | (dp[i][j][n] && dp[i + n][j + n][l - n]);
                        dp[i][j][l] = dp[i][j][l] | (dp[i][j + l - n][n] && dp[i + n][j][l - n]);
                    }
                }
            }
        }
        return dp[0][0][s1.size()];
    }
};
