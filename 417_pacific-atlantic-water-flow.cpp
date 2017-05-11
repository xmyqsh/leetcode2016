class Solution {
public:
    vector<pair<int, int> > result;
    vector<vector<int> > state;
    vector<pair<int, int>> pacificAtlantic(vector<vector<int>>& matrix) {
        if (matrix.empty() || matrix[0].empty()) return result;
        int m = matrix.size(), n = matrix[0].size();
        state.resize(m, vector<int>(n, 0));
        for (int i = 0; i != m; ++i) {
            dfs(matrix, i, 0, INT_MIN, 1);
            dfs(matrix, i, n - 1, INT_MIN, 2);
        }
        for (int j = 0; j != n; ++j) {
            dfs(matrix, 0, j, INT_MIN, 1);
            dfs(matrix, m - 1, j, INT_MIN, 2);
        }
        return result;
    }
    void dfs(const vector<vector<int> >& matrix, int x, int y, int pre, int sign) {
        if (x == -1 || y == -1 || x == matrix.size() || y == matrix[0].size() ||
            matrix[x][y] < pre || (state[x][y] & sign) == sign) return;
        state[x][y] |= sign;
        if (state[x][y] == 3) result.push_back(make_pair(x, y));
        dfs(matrix, x, y - 1, matrix[x][y], state[x][y]);
        dfs(matrix, x - 1, y, matrix[x][y], state[x][y]);
        dfs(matrix, x, y + 1, matrix[x][y], state[x][y]);
        dfs(matrix, x + 1, y, matrix[x][y], state[x][y]);
    } 
};
