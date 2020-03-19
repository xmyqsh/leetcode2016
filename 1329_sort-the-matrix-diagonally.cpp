class Solution {
public:
    vector<vector<int>> diagonalSort(vector<vector<int>>& mat) {
        int m = mat.size(), n = mat[0].size();
        for (int d = n - 1; d != -m; --d) {
            vector<int> diag;
            for (int i = 0, j = d + i; i != m; ++i, ++j) {
                if (j < 0) continue;
                if (j == n) break;
                diag.push_back(mat[i][j]);
            }
            sort(diag.begin(), diag.end());
            for (int i = 0, j = d + i, k = 0; i != m; ++i, ++j) {
                if (j < 0) continue;
                if (j == n) break;
                mat[i][j] = diag[k++];
            }
        }
        return mat;
    }
};
