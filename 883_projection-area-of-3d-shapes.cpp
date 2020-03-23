class Solution {
public:
    int projectionArea(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        int ret = m * n;
        for (int i = 0; i != m; ++i) {
            int v = -1;
            for (int j = 0; j != n; ++j) {
                v = max(v, grid[i][j]);
                if (grid[i][j] == 0) --ret;
            }
            ret += v;
        }
        for (int j = 0; j != n; ++j) {
            int v = -1;
            for (int i = 0; i != m; ++i) {
                v = max(v, grid[i][j]);
            }
            ret += v;
        }
        return ret;
    }
};
