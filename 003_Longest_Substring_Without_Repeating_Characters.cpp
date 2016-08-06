class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if (s.empty()) return 0;
        const int ASCII_MAX = 256;
        int alphabet[ASCII_MAX] = {0};
        int maxLen = 0, start = 0;
        for (int i = 0; i < s.size();) {
            if (alphabet[s[i]] == 0) {
                ++alphabet[s[i++]];
            } else {
                maxLen = max(maxLen, i - start);
                --alphabet[s[start++]];
            }
        }
        return max(maxLen, (int)s.size() - start);
    }
};
