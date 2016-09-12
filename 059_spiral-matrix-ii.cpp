class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int> > mat(n, vector<int>(n));
        int num = 1, rowBegin = 0, rowEnd = n - 1, colBegin = -1, colEnd = n - 1;
        while (colBegin < colEnd) {
            for (int j = ++colBegin; j <= colEnd; ++j) mat[rowBegin][j] = num++;
            for (int i = ++rowBegin; i <= rowEnd; ++i) mat[i][colEnd] = num++;
            for (int j = --colEnd; j >= colBegin; --j) mat[rowEnd][j] = num++;
            for (int i = --rowEnd; i >= rowBegin; --i) mat[i][colBegin] = num++;
        }
        return mat;
    }
};
