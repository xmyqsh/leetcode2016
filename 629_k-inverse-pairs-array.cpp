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

class Solution {
public:
    int kInversePairs(int n, int k) {
        vector<int> dp(k + 1, 0);
        const int M = 1e9 + 7;
        for (int i = 1; i != n + 1; ++i) {
            vector<int> tmp(k + 1, 0);
            for (int j = 0; j <= min(k, i * (i - 1) / 2); ++j) {
                if (j == 0) {
                    tmp[j] = 1;
                } else {
                    int val = (dp[j] + M - (j >= i ? dp[j - i] : 0)) % M;
                    tmp[j] = (tmp[j - 1] + val) % M;
                }
            }
            swap(dp, tmp);
        }
        return dp[k];
    }
};
