class Solution {
public:
    int findDerangement(int n) {
        vector<long long> dp(3, 0);
        dp[0] = 1; dp[1] = 0;
        const int MOD = 1e9 + 7;
        for (int i = 2; i != n + 1; ++i)
            dp[i % 3] = ((i - 1) * (dp[(i - 1) % 3] + dp[(i - 2) % 3])) % MOD;
        return dp[n % 3];
    }
};
