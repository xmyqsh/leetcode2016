class Solution {
public:
    int longestPalindromeSubseq(string s) {
        if (s.size() == 1) return 1;
        vector<vector<int> > dp(s.size(), vector<int>(s.size(), 1));
        for (int i = 0; i != s.size() - 1; ++i)
            dp[i][i + 1] = s[i] == s[i + 1] ? 2 : 1;
        for (int gap = 2; gap != s.size(); ++gap) {
            for (int i = 0, j = i + gap; j != s.size(); ++i, ++j)
                if (s[i] == s[j])
                    dp[i][j] = dp[i + 1][j - 1] + 2;
                else
                    dp[i][j] = max(dp[i + 1][j], dp[i][j - 1]);
        }
        return dp[0][s.size() - 1];
    }
};

/* 区间dp
dp[i][j] = max(dp[i + 1][j], dp[i][j - 1]),     s[i] != s[j]
                dp[i + 1][j - 1] + 2,           s[i] == s[j]
*/
