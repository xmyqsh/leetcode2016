class Solution {
public:
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        int m = dungeon.size(), n = dungeon[0].size();
        vector<int> f(n + 1, INT_MAX);
        for (int i = m - 1; i >= 0; --i) {
            if (i == m - 1) f[n] = 1;
            else f[n] = INT_MAX;
            for (int j = n - 1; j >= 0; --j) {
                const int t = min(f[j], f[j + 1]) - dungeon[i][j];
                f[j] = t <= 0 ? 1 : t;
            }
        }
        return f[0];
    }
};

// determine knight's minimum needed health before entering into every room
class Solution {
public:
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        int m = dungeon.size(), n = dungeon[0].size();
        vector<vector<int>> dp(m, vector<int>(n));
        dp[m - 1][n - 1] = max(1, 1 - dungeon[m - 1][n - 1]);
        for (int i = m - 2; i != -1; --i) dp[i][n - 1] = max(1, dp[i + 1][n - 1] - dungeon[i][n - 1]);
        for (int j = n - 2; j != -1; --j) dp[m - 1][j] = max(1, dp[m - 1][j + 1] - dungeon[m - 1][j]);
        for (int i = m - 2; i != -1; --i) {
            for (int j = n - 2; j != -1; --j) {
                dp[i][j] = max(1, min(dp[i + 1][j], dp[i][j + 1]) - dungeon[i][j]);
            }
        }
        return dp[0][0];
    }
};
