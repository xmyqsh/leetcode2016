class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> result;
        if (matrix.empty() || matrix[0].empty()) return result;
        int rowBegin = 0, rowEnd = matrix.size() - 1, colBegin = 0, colEnd = matrix[0].size() - 1;
        while (colBegin <= colEnd) {
            for (int j = colBegin; j <= colEnd; ++j)
                result.push_back(matrix[rowBegin][j]);
            if (++rowBegin > rowEnd) break;
            for (int i = rowBegin; i <= rowEnd; ++i)
                result.push_back(matrix[i][colEnd]);
            if (colBegin > --colEnd) break;
            for (int j = colEnd; j >= colBegin; --j)
                result.push_back(matrix[rowEnd][j]);
            if (rowBegin > --rowEnd) break;
            for (int i = rowEnd; i >= rowBegin; --i)
                result.push_back(matrix[i][colBegin]);
            ++colBegin;
        }
        return result;
    }
};
