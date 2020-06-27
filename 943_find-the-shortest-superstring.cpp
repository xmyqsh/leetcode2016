class Solution {
public:
    string shortestSuperstring(vector<string>& A) {
        int n = A.size();
        vector<vector<int>> overlap(n, vector<int>(n, 0));
        for (int i = 0; i != n; ++i) {
            for (int j = 0; j != n; ++j) {
                if (i == j) continue;
                overlap[i][j] = endwith(A[i], A[j]);
            }
        }
        int numState = (1 << A.size());
        vector<vector<int>> dp(numState, vector<int>(n, 241));
        vector<vector<pair<int, int>>> pre(numState, vector<pair<int, int>>(n, {-1, -1}));
        int minLen = 241, endIdx;
        for (int i = n - 1; i != -1; --i) {
            auto [curLen, curEndIdx] = shortestSuperstring(A, overlap, dp, pre, numState - 1, i);
            if (curLen < minLen) {
                minLen = curLen;
                endIdx = curEndIdx;
            }
        }
        int mask = numState - 1;
        string ret(A[endIdx]);
        while (mask != -1) {
            auto [preMask, preEndIdx] = pre[mask][endIdx];
            if (preMask == -1) break;
            ret = A[preEndIdx].substr(0, A[preEndIdx].size() - overlap[preEndIdx][endIdx]) + ret;
            mask = preMask; endIdx = preEndIdx;
        }
        return ret;
    }
    tuple<int, int> shortestSuperstring(vector<string>& A, vector<vector<int>>& overlap, vector<vector<int>>& dp,
                                        vector<vector<pair<int, int>>>& pre, int mask, int idx) {
        if (dp[mask][idx] != 241) return {dp[mask][idx], idx};
        if (mask == (1 << idx)) {
            dp[mask][idx] = A[idx].size();
            return {A[idx].size(), idx};
        }
        int minLen = 241;
        assert((mask & (1 << idx)) != 0);
        int preMask = (mask & ~(1 << idx));
        for (int i = 0, oneBit = 1; i != A.size(); ++i, oneBit <<= 1) {
            if ((preMask & oneBit) == 0) continue;
            assert(i != idx);
            auto [curLen, curEndIdx] = shortestSuperstring(A, overlap, dp, pre, preMask, i);
            assert(curEndIdx != idx);
            int nextLen = curLen + A[idx].size() - overlap[curEndIdx][idx];
            if (nextLen < minLen) {
                minLen = nextLen;
                pre[mask][idx] = {preMask, curEndIdx};
            }
        }
        dp[mask][idx] = minLen;
        return {minLen, idx};
    }
    int endwith(const string& a, const string& b) {
        int na = a.size(), nb = b.size();
        int len;
        for (len = min(na, nb); len != 0; --len) {
            int i, j;
            for (i = na - len, j = 0; i != na && a[i] == b[j]; ++i, ++j);
            if (i == na) return len;
        }
        assert(len == 0);
        return len;
    }
};
