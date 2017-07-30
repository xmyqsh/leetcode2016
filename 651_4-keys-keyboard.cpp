class Solution {
public:
    int maxA(int N) {
        vector<int> dp(N + 1);
        dp[1] = 1;
        for (int i = 2; i <= N; ++i) {
            dp[i] = max(i, dp[i - 1] + 1);
            for (int j = 2; j * 2 <= i - 1; ++j) {
                int k = i - 1 - j;
                dp[i] = max(dp[i], dp[j] * k);
                dp[i] = max(dp[i], dp[k] * j);
            }
        }
        return dp[N];
    }
};
