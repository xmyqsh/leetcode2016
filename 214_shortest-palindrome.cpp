class Solution {
public:
    string shortestPalindrome(string s) {
        int mid = s.size() / 2;
        if (mid + mid + 1 == s.size()) {
            int i, j;
            for (i = mid - 1, j = mid + 1; i >= 0 && s[i] == s[j]; --i, ++j);
            if (i < 0) return s;
        }
        string result;
        for (--mid; mid >= 0; --mid) {
            int i, j;
            for (i = mid, j = mid + 1; i >= 0 && s[i] == s[j]; --i, ++j);
            if (i < 0) {
                if (j == s.size()) return s;
                result = s.substr(j, s.size() - j);
                reverse(result.begin(), result.end());
                result.append(s);
                break;
            }
            for (i = mid - 1, j = mid + 1; i >= 0 && s[i] == s[j]; --i, ++j);
            if (i < 0) {
                if (j == s.size()) return s;
                result = s.substr(j, s.size() - j);
                reverse(result.begin(), result.end());
                result.append(s);
                break;
            }
        }
        return result;
    }
};
