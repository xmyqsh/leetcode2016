class Solution {
public:
    vector<vector<int>> imageSmoother(vector<vector<int>>& M) {
        vector<vector<int> > result;
        if (!M.size() || !M[0].size()) return result;
        int m = M.size(), n = M[0].size();
        result = vector<vector<int> >(m, vector<int>(n, 0));
        for (int i = 0; i != m; ++i) {
            for (int j = 0; j != n; ++j) {
                int ret = 0, cnt = 0;
                for (int p = -1; p != 2; ++p) {
                    for (int q = -1; q != 2; ++q) {
                        int x = i + p, y = j + q;
                        if (x == -1 || y == -1 || x == m || y == n) continue;
                        ret += M[x][y];
                        ++cnt;
                    }
                }
                result[i][j] = ret / cnt;
            }
        }
        return result;
    }
};
