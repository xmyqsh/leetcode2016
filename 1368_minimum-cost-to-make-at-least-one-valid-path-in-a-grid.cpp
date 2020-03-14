class Solution {
public:
    int minCost(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> dp(m, vector<int>(n, m + n - 2));
        dp[0][0] = 0;
        queue<tuple<int, int>> q;
        q.push(tuple(0, 0));
        vector<vector<int>> dirs = {{0, 0}, {0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        while (!q.empty()) {
            auto [i, j] = q.front(); q.pop();
            for (int k = 1; k != 5; ++k) {
                auto x = i + dirs[k][0];
                auto y = j + dirs[k][1];
                if (x == -1 || y == -1 || x == m || y == n) continue;
                if (grid[i][j] == k) {
                    if (dp[x][y] > dp[i][j]) {
                        dp[x][y] = dp[i][j];
                        q.push(tuple(x, y));
                    }
                } else { // grid[i][j] != k
                    if (dp[x][y] > dp[i][j] + 1) {
                        dp[x][y] = dp[i][j] + 1;
                        q.push(tuple(x, y));
                    }
                }
            }
        }
        return dp[m - 1][n - 1];
    }
};
