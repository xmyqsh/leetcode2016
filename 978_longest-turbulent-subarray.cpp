class Solution {
public:
    int maxTurbulenceSize(vector<int>& A) {
        vector<vector<int>> dp(A.size(), vector<int>(2, 1));
        dp[0][0] = dp[0][1] = 1;
        int ret = 1;
        for (int i = 1; i != A.size(); ++i) {
            if (A[i - 1] < A[i]) {
                dp[i][1] = max(dp[i][1], 1 + dp[i - 1][0]);
            } else if (A[i - 1] > A[i]) {
                dp[i][0] = max(dp[i][0], 1 + dp[i - 1][1]);
            }
            ret = max(ret, max(dp[i][0], dp[i][1]));
        }
        return ret;
    }
};
