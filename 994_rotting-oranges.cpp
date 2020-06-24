class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        queue<pair<int, int>> q;
        int ret = 0;
        for (int i = 0; i != m; ++i) {
            for (int j = 0; j != n; ++j) {
                if (grid[i][j] == 2) {
                    q.push({i, j});
                    ret = -1;
                }
            }
        }
        while (!q.empty()) {
            int s = q.size();
            while (s--) {
                auto [x, y] = q.front(); q.pop();
                for (const auto& v : vector<vector<int>>({{-1, 0}, {1, 0}, {0, -1}, {0, 1}})) {
                    int i = x + v[0], j = y + v[1];
                    if (i == -1 || j == -1 || i == m || j == n) continue;
                    if (grid[i][j] != 1) continue;
                    grid[i][j] = 2;
                    q.push({i, j});
                }
            }
            ++ret;
        }
        for (int i = 0; i != m; ++i) {
            for (int j = 0; j != n; ++j) {
                if (grid[i][j] == 1) return -1;
            }
        }
        return ret;
    }
};
