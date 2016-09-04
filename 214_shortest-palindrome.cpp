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

class Solution {
public:
    string shortestPalindrome(string s) {
        int b = 0, e = s.size() - 1;
        while (b < e)
            if (s[b] != s[e]) break;
            else { ++b; --e; }
        if (b >= e) return s;
        string s2 = s;
        reverse(s2.begin(), s2.end());
        int n = s.size(), k, i, j;
        for (k = 0; k < n; ++k) {
            if (s2.substr(k) == s.substr(0, n - k)) break;
            /*  // time out.  why is this slower than substr ?
            for (i = k, j = 0; i < n && s2[i] == s[j]; ++i, ++j);
            if (i == n) break;
            */
        }
        return s2.substr(0, k).append(s);
    }
};
