class Solution {
public:
    int minCost(vector<int>& houses, vector<vector<int>>& cost, int m, int n, int target) {
        vector<vector<vector<int>>> dp(m, vector<vector<int>>(n, vector<int>(target, 100000000)));

        if (houses[0] == 0) {
            for (int j = 0; j != n; ++j) {
                dp[0][j][0] = cost[0][j];
            }
        } else dp[0][houses[0] - 1][0] = 0;

        for (int i = 1; i != m; ++i) {
            if (houses[i] != 0) {
                int color = houses[i] - 1;
                for (int k = 0; k != target; ++k) {
                    for (int c = 0; c != n; ++c) {
                        if (c == color) dp[i][color][k] = min(dp[i][color][k], dp[i - 1][c][k]);
                        else dp[i][color][k] = k != 0 ? min(dp[i][color][k], dp[i - 1][c][k - 1]) : dp[i][color][k];
                    }
                }
            } else {
                for (int j = 0; j != n; ++j) {
                    for (int k = 0; k != target; ++k) {
                        for (int c = 0; c != n; ++c) {
                            if (j == c) dp[i][j][k] = min(dp[i][j][k], dp[i - 1][c][k] + cost[i][j]);
                            else dp[i][j][k] = k != 0 ? min(dp[i][j][k], dp[i - 1][c][k - 1] + cost[i][j]) : dp[i][j][k];
                        }
                    }
                }
            }
        }

        int minC = 100000000;
        for (int j = 0; j != n; ++j) minC = min(minC, dp[m - 1][j][target - 1]);
        return minC >= 100000000 ? -1 : minC;
    }
};
