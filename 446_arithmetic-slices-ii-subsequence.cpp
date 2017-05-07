class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& A) {
        if (A.size() < 3) return 0;
        vector<unordered_map<int, int> > dp(A.size());
        int result = 0;
        for (int i = 1; i != A.size(); ++i) {
            for (int j = 0; j != i; ++j) {
                long gap = (long)A[i] - (long)A[j];
                if (gap < INT_MIN || gap > INT_MAX) continue;
                dp[i][gap] += 1;
                if (dp[j].count(gap)) {
                    dp[i][gap] += dp[j][gap];
                    result += dp[j][gap];
                }
            }
        }
        return result;
    }
};
