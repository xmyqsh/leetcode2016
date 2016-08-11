class Solution {
public:
    int strStr(string haystack, string needle) {
        if (needle.empty()) return 0;
        if (haystack.empty()) return -1;
        int i = 0, n = haystack.size(), m = needle.size();
        if (n < m) return -1;
        for (; i + m <= n; ++i) {
            int j = 0;
            for (; j < m && haystack[i + j] == needle[j]; ++j);
            if (j == m) break;
        }
        return i + m <= n ? i : -1;
    }
};
