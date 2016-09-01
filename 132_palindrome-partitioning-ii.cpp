class Solution {
public:
    int minCut(string s) {
        vector<int> f(s.size() + 1, 0);
        for (int i = 0; i <= s.size(); ++i) f[i] = i - 1;
        for (int i = 0; i < s.size(); ++i) {
            for (int j = 0; i - j >= 0 && i + j < s.size() && s[i - j] == s[i + j]; ++j)
                f[i + j + 1] = min(f[i + j + 1], f[i - j] + 1);
            for (int j = 1; i - j + 1 >= 0 && i + j < s.size() && s[i - j + 1] == s[i + j]; ++j)
                f[i + j + 1] = min(f[i + j + 1], f[i - j + 1] + 1);
        }
        return f[s.size()];
    }
};
