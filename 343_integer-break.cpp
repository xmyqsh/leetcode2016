class Solution {
public:
    int integerBreak(int n) {
        if (n == 2) return 1;
        if (n == 3) return 2;
        switch (n % 3) {
            case 0: return pow(3, n / 3);
            case 1: return pow(3, n / 3 - 1) * 4;
            case 2: return pow(3, n / 3) * 2;
        }
        return 0;
    }
};

//DP
class Solution {
public:
    int integerBreak(int n) {
        if (n == 2) return 1;
        vector<int> dp(n + 1, 0);
        dp[2] = 1;
        for (int i = 3; i <= n; ++i)
            for (int j = 2; j < i; ++j)
                dp[i] = max(dp[i], j * max(i - j, dp[i - j]));
        return dp[n];
    }
};
