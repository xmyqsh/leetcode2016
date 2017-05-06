class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<int> > vertical(m, vector<int>(n + 1, 0));
        vector<vector<int> > horizen(m + 1, vector<int>(n, 0));
        for (int i = 0; i != m; ++i) {
            for (int j = 0; j != n; ++j) {
                if (grid[i][j]) {
                    ++vertical[i][j]; ++vertical[i][j + 1];
                    ++horizen[i][j]; ++horizen[i + 1][j];
                }
            }
        }
        int cnt = 0;
        for (auto& row : vertical)
            for (auto e : row)
                if (e == 1)
                    ++cnt;
        for (auto& row : horizen)
            for (auto e : row)
                if (e == 1)
                    ++cnt;
        return cnt;
    }
};
