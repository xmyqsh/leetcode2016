// TODO
// Typical wrong solution, wrong state manupilation
class Solution {
public:
    int findGoodStrings(int n, string s1, string s2, string evil) {
        set<char> st;
        for (auto c : s1) st.insert(c);
        if (st.size() == 1 && *(st.begin()) == 'a') return solve(n, s2, evil);
        if (s1.find(evil) != string::npos) {
            return solve(n, s2, evil) - solve(n, s1, evil);
        }
        return solve(n, s2, evil) - solve(n, s1, evil) + 1;
    }
    int solve(int n, const string& s, const string& evil) {
        int pos = 0;
        vector<int> dp(n, -1);
        string pre;
        return dfs(n, 0, pre, s, evil, dp, true);
    }
    int dfs(int n, int pos, string pre, const string& s, const string& evil, vector<int>& dp, bool limit) {
        if (pos == n) return 1;
        if (pre.size() == evil.size()) pre = pre.substr(1);
        if (!limit && dp[pos] != -1) return dp[pos];
        char up = limit ? s[pos] : 'z';
        long long tmp = 0;
        for (char c = 'a'; c <= up; ++c) {
            if (pre + c == evil) continue;
            tmp += dfs(n, pos + 1, pre + c, s, evil, dp, limit && c == up);
            tmp %= 1000000007;
        }
        if (!limit) dp[pos] = tmp;
        return tmp;
    }
};
