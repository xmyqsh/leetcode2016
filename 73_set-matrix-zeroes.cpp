class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        if (matrix.empty() || matrix[0].empty()) return;
        bool row = false, col = false;
        int i, j;
        for (i = 0; i != matrix.size() && matrix[i][0]; ++i);
        if (i != matrix.size()) col = true;
        for (j = 0; j != matrix[0].size() && matrix[0][j]; ++j);
        if (j != matrix[0].size()) row = true;
        for (i = 1; i < matrix.size(); ++i)
            for (j = 1; j < matrix[0].size(); ++j)
                if (matrix[i][j] == 0) matrix[i][0] = 0, matrix[0][j] = 0;
        for (i = 1; i != matrix.size(); ++i)
            for (j = 1; j != matrix[0].size(); ++j)
                if (matrix[i][0] == 0 || matrix[0][j] == 0) matrix[i][j] = 0;
        if (row) for (j = 0; j != matrix[0].size(); ++j) matrix[0][j] = 0;
        if (col) for (i = 0; i != matrix.size(); ++i) matrix[i][0] = 0;
    }
};
