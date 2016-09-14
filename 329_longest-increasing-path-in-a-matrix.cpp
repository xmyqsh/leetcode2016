class Solution {
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        if (matrix.empty() || matrix[0].empty()) return 0;
        vector<vector<int> > cache(matrix.size(), vector<int>(matrix[0].size(), 0));
        int result = 0;
        for (int i = 0; i != matrix.size(); ++i)
            for (int j = 0; j != matrix[0].size(); ++j)
                result = max(result, travel(INT_MIN, i, j, matrix, cache));
        return result;
    }
    int travel(int val, int i, int j, const vector<vector<int> >& matrix, vector<vector<int> >& cache) {
        if (i == -1 || j == -1 || i == matrix.size() || j == matrix[0].size() || matrix[i][j] <= val) return 0;
        if (cache[i][j]) return cache[i][j];
        cache[i][j] = travel(matrix[i][j], i - 1, j, matrix, cache);
        cache[i][j] = max(cache[i][j], travel(matrix[i][j], i, j + 1, matrix, cache));
        cache[i][j] = max(cache[i][j], travel(matrix[i][j], i + 1, j, matrix, cache));
        cache[i][j] = max(cache[i][j], travel(matrix[i][j], i, j - 1, matrix, cache)) + 1;
        return cache[i][j];
    }
};
