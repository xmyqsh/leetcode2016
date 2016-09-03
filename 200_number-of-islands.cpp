class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        if (!grid.size() || !grid[0].size()) return 0;
        vector<vector<int> > visited(grid.size(), vector<int>(grid[0].size(), 0));
        int count = 0;
        for (int i = 0; i < grid.size(); ++i) {
            for (int j = 0; j < grid[0].size(); ++j) {
                if (grid[i][j] == '0' || visited[i][j]) continue;
                ++count;
                dfs(grid, visited, i, j);
            }
        }
        return count;
    }
    void dfs(const vector<vector<char> >& grid, vector<vector<int> >& visited, int i, int j) {
        if (grid[i][j] == '0' || visited[i][j]) return;
        visited[i][j] = 1;
        if (i > 0) dfs(grid, visited, i - 1, j);
        if (j > 0) dfs(grid, visited, i, j - 1);
        if (i + 1 < grid.size()) dfs(grid, visited, i + 1, j);
        if (j + 1 < grid[0].size()) dfs(grid, visited, i, j + 1);
    }
};
