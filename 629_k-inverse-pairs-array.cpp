class Solution {
public:
    int kInversePairs(int n, int k) {
        if (n == 0) return 0;
        if (k == 0) return 1;
        vector<vector<int> > dp(n + 1, vector<int>(k + 1, 0));
        const int M = 1e9 + 7;
        for (int i = 1; i != n + 1; ++i) {
            for (int j = 0; j != k + 1; ++j) {
                if (j == 0) {
                    dp[i][j] = 1;
                } else {
                    int val = (dp[i - 1][j] + M - (j >= i ? dp[i - 1][j - i]: 0)) % M;
                    dp[i][j] = (dp[i][j - 1] + val) % M;
                }
            }
        }
        return (dp[n][k] + M - dp[n][k - 1]) % M;
    }
};
