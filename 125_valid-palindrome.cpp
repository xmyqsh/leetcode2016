class Solution {
public:
    bool isPalindrome(string s) {
        int b = 0, e = s.size() - 1;
        while (b < e) {
            if (!isalnum(s[b])) ++b;
            else if (!isalnum(s[e])) --e;
            else if (tolower(s[b]) != tolower(s[e])) return false;
            else { ++b; --e; }
        }
        return true;
    }
};
