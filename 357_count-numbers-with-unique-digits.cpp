class Solution {
public:
    int countNumbersWithUniqueDigits(int n) {
        if (n == 0) return 1;
        vector<int> dp(min(n + 1, 11), 0);
        dp[1] = 10; dp[2] = 9 * 9;
        for (int i = 3, j = 8; i <= min(n, 10); ++i, --j) dp[i] = dp[i - 1] * j;
        int result = 0;
        for (int i = 0; i <= min(n, 10); ++i) result += dp[i];
        return result;
    }
};
