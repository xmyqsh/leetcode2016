class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        if (grid.empty() || grid[0].empty()) return 0;
        vector<int> f(grid[0].size() + 1, INT_MAX);
        f[1] = 0;
        for (int i = 0; i < grid.size(); ++i)
            for (int j = 0; j < grid[0].size(); ++j)
                f[j + 1] = min(f[j], f[j + 1]) + grid[i][j];
        return f[grid[0].size()];
    }
};
