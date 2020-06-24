class Solution {
public:
    int uniquePathsIII(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        int cnt = 0, sx, sy;
        for (int i = 0; i != m; ++i) {
            for (int j = 0; j != n; ++j) {
                if (grid[i][j] == -1) ++cnt;
                else if (grid[i][j] == 1) { sx = i; sy = j; }
            }
        }
        int ret = 0;
        dfs(grid, m, n, sx, sy, m * n, cnt + 1, ret);
        return ret;
    }
    void dfs(vector<vector<int>>& grid, int m, int n, int x, int y, int N, int cnt, int& ret) {
        if (x == -1 || y == -1 || x == m || y == n) return;
        if (grid[x][y] == -1) return;
        if (cnt == N) {
            if (grid[x][y] == 2) ++ret;
            return;
        }
        if (grid[x][y] == 2) return;
        int tmp = grid[x][y];
        grid[x][y] = -1;
        dfs(grid, m, n, x + 1, y, N, cnt + 1, ret);
        dfs(grid, m, n, x - 1, y, N, cnt + 1, ret);
        dfs(grid, m, n, x, y + 1, N, cnt + 1, ret);
        dfs(grid, m, n, x, y - 1, N, cnt + 1, ret);
        grid[x][y] = tmp;
    }
};
