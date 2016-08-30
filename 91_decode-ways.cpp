class Solution {
public:
    int numDecodings(string s) {
        if (s.empty() || s[0] == '0') return 0;
        int prev = 0, cur = 1;
        for (int i = 0; i < s.size(); ++i) {
            if (s[i] == '0') cur = 0;
            if (i < 1 || !(s[i - 1] == '1' || (s[i - 1] == '2' && s[i] <= '6'))) prev = 0;
            cur += prev;
            prev = cur - prev;
        }
        return cur;
    }
};
