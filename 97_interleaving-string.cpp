class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        if (s1.size() + s2.size() != s3.size()) return false;
        if (s1.empty()) return s2 == s3;
        if (s2.empty()) return s1 == s3;
        vector<int> f(s2.size() + 1, true);
        for (int j = 1; j <= s2.size(); ++j)
            f[j] = (s2[j - 1] == s3[j - 1]) && f[j - 1];
        for (int i = 1; i <= s1.size(); ++i) {
            f[0] = (s1[i - 1] == s3[i - 1]) && f[0];
            for (int j = 1; j <= s2.size(); ++j)
                f[j] = ((s2[j - 1] == s3[i + j - 1]) && f[j - 1]) || ((s1[i - 1] == s3[i + j - 1]) && f[j]);
        }
        return f[s2.size()];
    }
};
