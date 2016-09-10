class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        if (matrix.empty() || matrix[0].empty()) return;
        for (int i = 0; i < matrix.size() / 2; ++i)
            for (int j = 0; j < matrix[0].size(); ++j)
                swap(matrix[i][j], matrix[matrix.size() - i - 1][j]);
        for (int i = 0; i < matrix.size(); ++i)
            for (int j = 0; j < i; ++j)
                swap(matrix[i][j], matrix[j][i]);
    }
};
