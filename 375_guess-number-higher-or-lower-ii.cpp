// Top-down
class Solution {
public:
    int getMoneyAmount(int n) {
        vector<vector<int> > dp(n + 1, vector<int>(n + 1, 0));
        return travel(dp, 1, n);
    }
    int travel(vector<vector<int> >& dp, int b, int e) {
        if (b >= e) return 0;
        if (dp[b][e]) return dp[b][e];
        dp[b][e] = INT_MAX;
        for (int i = b; i <= e; ++i)
            dp[b][e] = min(dp[b][e], i + max(travel(dp, b, i - 1), travel(dp, i + 1, e)));
        return dp[b][e];
    }
};

/* minimax, 区间dp
dp[i,j] = min{x_k + max{dp[i, x_k - 1], dp[x_k + 1, j]}}
*/

// Bottom-up
class Solution {
public:
    int getMoneyAmount(int n) {
        vector<vector<int> > dp(n + 1, vector<int>(n + 1, 0));
        for (int gap = 2; gap <= n; ++gap) {
            for (int i = 1, j = i + gap - 1; j <= n; ++i, ++j) {
                dp[i][j] = min(i + dp[i + 1][j], j + dp[i][j - 1]);
                for (int k = i + 1; k < j; ++k)
                    dp[i][j] = min(dp[i][j], k + max(dp[i][k - 1], dp[k + 1][j]));
            }
        }
        return dp[1][n];
    }
};
