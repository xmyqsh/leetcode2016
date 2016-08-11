// to be optimize
class Solution {
public:
    string longestPalindrome(string s) {
        if (s.empty()) return 0;
        int maxLen = 1, start = 0;
        for (int i = 0; i < s.size(); ++i) {
            int l = i - 1, r = i + 1;
            while (l >= 0 && s[l] == s[i]) --l;
            while (r < s.size() && s[i] == s[r]) ++r;
            while (l >= 0 && r < s.size() && s[l] == s[r]) { --l; ++r; }
            int len = r - l - 1;
            if (maxLen < len) {
                maxLen = len;
                start = l + 1;
            }
        }
        return s.substr(start, maxLen);
    }
};
