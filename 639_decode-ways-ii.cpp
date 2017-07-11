class Solution {
public:
    int numDecodings(string s) {
        if (s.empty() || s[0] == '0') return 0;
        long long prev = 1, cur = (s[0] == '*' ? 9 : 1);
        const int MOD = 1e9 + 7;
        for (int i = 1; i != s.size(); ++i) {
            if (s[i] == '*') {
                int tmp = cur;
                if (s[i - 1] == '*') {
                    cur = cur * 9 + prev * (9 + 6);
                } else {
                    cur = cur * 9 + prev * (s[i - 1] == '1' ? 9 : (s[i - 1] == '2' ? 6 : 0));
                }
                prev = tmp;
            } else {
                if (s[i] == '0') cur = 0;
                int tmp = cur;
                if (s[i - 1] == '*') {
                    cur = cur + prev * (s[i] <= '6' ? 2 : 1);
                } else {
                    cur = cur + prev * (s[i - 1] == '1' || (s[i - 1] == '2' && s[i] <= '6') ? 1 : 0);
                }
                prev = tmp;
            }
            cur %= MOD;
        }
        return cur;
    }
};
