class Solution {
public:
    int findPaths(int m, int n, int N, int i, int j) {
        vector<vector<vector<unsigned int> > > dp(N + 1, vector<vector<unsigned int> >(m, vector<unsigned int>(n, 0)));
        for (int k = 1; k <= N; ++k)
            for (int p = 0; p != m; ++p)
                for (int q = 0; q != n; ++q)
                    dp[k][p][q] = ((p == 0 ? 1 : dp[k - 1][p - 1][q]) +
                                   (q == 0 ? 1 : dp[k - 1][p][q - 1]) +
                                   (p + 1 == m ? 1 : dp[k - 1][p + 1][q]) +
                                   (q + 1 == n ? 1 : dp[k - 1][p][q + 1])) % 1000000007;
        return dp[N][i][j];
    }
};

class Solution {
public:
    int findPaths(int m, int n, int N, int i, int j) {
        vector<vector<vector<unsigned int> > > dp(2, vector<vector<unsigned int> >(m, vector<unsigned int>(n, 0)));
        for (int k = 1; k <= N; ++k)
            for (int p = 0; p != m; ++p)
                for (int q = 0; q != n; ++q)
                    dp[k % 2][p][q] = ((p == 0 ? 1 : dp[(k - 1) % 2][p - 1][q]) +
                                       (q == 0 ? 1 : dp[(k - 1) % 2][p][q - 1]) +
                                       (p + 1 == m ? 1 : dp[(k - 1) % 2][p + 1][q]) +
                                       (q + 1 == n ? 1 : dp[(k - 1) % 2][p][q + 1])) % 1000000007;
        return dp[N % 2][i][j];
    }
};
