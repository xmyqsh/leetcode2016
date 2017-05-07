class Solution {
public:
    int findSubstringInWraproundString(string p) {
        if (p.empty()) return 0;
        vector<int> cnt(26, 0);
        int result = 1, len = 1;
        cnt[p[0] - 'a'] = 1;
        for (int i = 1; i != p.size(); ++i) {
            int cur = p[i] - 'a';
            if (i > 0 && p[i - 1] != (cur - 1 + 26) % 26 + 'a')
                len = 0;
            if (++len > cnt[cur]) {
                result += len - cnt[cur];
                cnt[cur] = len;
            }
        }
        return result;
    }
};
