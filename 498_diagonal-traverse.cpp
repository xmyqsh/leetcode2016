class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& matrix) {
        if (matrix.empty() || matrix[0].empty()) return vector<int>();
        int row = 0, col = 0, dir = 0, m = matrix.size(), n = matrix[0].size();
        vector<vector<int> > step = {{-1, 1}, {1, -1}};
        vector<int> result(m * n);
        for (int i = 0; i != result.size(); ++i) {
            result[i] = matrix[row][col];
            row += step[dir][0];
            col += step[dir][1];
            if (row == m) { row = m - 1; col += 2; dir = 1 - dir; }
            else if (col == n) { col = n - 1; row += 2; dir = 1 - dir; }
            else if (row < 0) { row = 0; dir = 1 - dir; }
            else if (col < 0) { col = 0; dir = 1 - dir; }
        }
        return result;
    }
};
