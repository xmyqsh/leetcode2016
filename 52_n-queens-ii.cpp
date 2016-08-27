class Solution {
public:
    int totalNQueens(int n) {
        int result = 0;
        vector<int> flag(5 * n, 1);
        dfs(&result, flag, n, 0);
        return result;
    }
    void dfs(int* result, vector<int>& flag, int N, int row) {
        if (row == N) {
            (*result)++;
            return;
        }
        for (int col = 0; col < N; ++col) {
            if (flag[col] && flag[N + row + col] && flag[4 * N + row - col]) {
                flag[col] = flag[N + row + col] = flag[4 * N + row - col] = 0;
                dfs(result, flag, N, row + 1);
                flag[col] = flag[N + row + col] = flag[4 * N + row - col] = 1;
            }
        }
    }
};
