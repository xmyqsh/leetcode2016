class Solution {
public:
    string removeDuplicateLetters(string s) {
        if (s.empty()) return "";
        vector<int> count(26, 0);
        int pos = 0;
        for (auto c : s) ++count[c - 'a'];
        for (int i = 0; i != s.size(); ++i) {
            if (s[i] < s[pos]) pos = i;
            if (--count[s[i] - 'a'] == 0) break;
        }
        stringstream ss;
        for (int i = pos + 1; i != s.size(); ++i) if (s[i] != s[pos]) ss << s[i];
        return s[pos] + removeDuplicateLetters(ss.str());
    }
};
