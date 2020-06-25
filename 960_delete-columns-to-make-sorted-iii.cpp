class Solution {
public:
    int minDeletionSize(vector<string>& A) {
        vector<int> dp(A[0].size(), 1);
        int maxLen = 1;
        for (int i = 1; i != A[0].size(); ++i) {
            for (int j = i - 1, k; j != -1; --j) {
                for (k = 0; k != A.size() && A[k][j] <= A[k][i]; ++k);
                if (k == A.size()) {
                    dp[i] = max(dp[i], 1 + dp[j]);
                    maxLen = max(maxLen, dp[i]);
                }
            }
        }
        return A[0].size() - maxLen;
    }
};
