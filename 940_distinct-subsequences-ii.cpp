class Solution {
public:
    int distinctSubseqII(string S) {
        vector<long long> dp(S.size() + 1, 0); dp[0] = 1;
        unordered_map<char, int> lastIdx;
        for (int i = 1; i != S.size() + 1; ++i) {
            dp[i] = 2 * dp[i - 1] - (lastIdx.count(S[i - 1]) ? dp[lastIdx[S[i - 1]] - 1] : 0);
            dp[i] %= 1000000007;
            lastIdx[S[i - 1]] = i;
        }
        return (dp[S.size()] + 1000000007 - 1) % 1000000007;
    }
};
