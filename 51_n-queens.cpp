class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string> > result;
        vector<string> Q(n, string(n, '.'));
        vector<int> flag(5 * n, 1);
        dfs(&result, Q, flag, 0);
        return result;
    }
    void dfs(vector<vector<string> >* result, vector<string>& Q, vector<int>& flag, int row) {
        const int N = Q.size();
        if (row == N) {
            result->push_back(Q);
            return;
        }
        for (int col = 0; col < N; ++col) {
            if (flag[col] && flag[N + row + col] && flag[4 * N + row - col]) {
                flag[col] = flag[N + row + col] = flag[4 * N + row - col] = 0;
                Q[row][col] = 'Q';
                dfs(result, Q, flag, row + 1);
                Q[row][col] = '.';
                flag[col] = flag[N + row + col] = flag[4 * N + row - col] = 1;
            }
        }
    }
};
