class Solution {
public:
    bool isSubsequence(string s, string t) {
        if (t.empty()) return s.empty();
        if (s.empty()) return true;
        int i, j;
        for (i = 0, j = 0; i < s.size() && j < t.size(); ++j)
            if (s[i] == t[j]) ++i;
        return i == s.size();
    }
};
