class Solution {
public:
    bool validPalindrome(string s) {
        return validPalindrome(s, 0, s.size() - 1);
    }
    bool validPalindrome(const string& s, int b, int e) {
        while (b < e && s[b] == s[e]) {
            ++b; --e;
        }
        if (b >= e) return true;
        return validPalindrome1(s, b + 1, e) ||
               validPalindrome1(s, b, e - 1);
    }
    bool validPalindrome1(const string& s, int b, int e) {
        while (b < e && s[b] == s[e]) {
            ++b; --e;
        }
        return b >= e;
    }
};
