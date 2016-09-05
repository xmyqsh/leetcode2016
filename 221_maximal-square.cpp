class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        if (matrix.empty()) return 0;
        vector<int> f(matrix[0].size(), 0);
        int maxEdge = 0;
        for (int i = 0; i < matrix.size(); ++i) {
            int last = 0;
            for (int j = 0; j < matrix[0].size(); ++j) {
                int tmp = f[j];
                f[j] = matrix[i][j] == '1' ? min(last, min(f[j - 1], f[j])) + 1 : 0;
                last = tmp;
                maxEdge = max(maxEdge, f[j]);
            }
        }
        return maxEdge * maxEdge;
    }
};
