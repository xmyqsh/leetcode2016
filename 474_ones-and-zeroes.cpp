class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        vector<vector<int> > dp(m + 1, vector<int>(n + 1, 0));
        int zeros, ones;
        for (auto str : strs) {
            count(str, zeros, ones);
            for (int i = m; i >= 0; --i)
                for (int j = n; j >= 0; --j)
                    if (i >= zeros && j >= ones)
                        dp[i][j] = max(dp[i][j], 1 + dp[i - zeros][j - ones]);
        }
        return dp[m][n];
    }
    void count(const string& str, int& zeros, int& ones) {
        zeros = 0; ones = 0;
        for (auto c : str)
            c == '0' ? ++zeros : ++ones;
    }
};
