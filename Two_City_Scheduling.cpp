class Solution {
public:
    int twoCitySchedCost(vector<vector<int>>& costs) {
        int N = costs.size() / 2;
        vector<vector<vector<int>>> dp(2 * N + 1, vector<vector<int>>(N + 1, vector<int>(N + 1, 100005)));
        dp[0][0][0] = 0;
        for (int i = 1; i != costs.size() + 1; ++i) {
            for (int idxA = 0; idxA <= min(i, N); ++idxA) {
                int idxB = i - idxA;
                if (idxB > N) continue;
                dp[i][idxA][idxB] = min(idxA ? dp[i - 1][idxA - 1][idxB] + costs[i - 1][0] : 100005,
                                        idxB ? dp[i - 1][idxA][idxB - 1] + costs[i - 1][1] : 100005);
            }
        }
        return dp[2 * N][N][N];
    }
    /*
    dp[2 * N][N][N] = min(dp[2 * N - 1][N - 1][N] + costs[2 * N - 1][0],
                          dp[2 * N - 1][N][N - 1] + costs[2 * N - 1][1]);
    dp[1][1][0] = ?
    dp[1][0][1] = ?
    */
};
