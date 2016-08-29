class Solution {
public:
    string minWindow(string s, string t) {
        if (t.empty() || t.size() > s.size()) return "";
        const int ASCII_MAX = 256;
        vector<int> appearedNum(ASCII_MAX, 0);
        vector<int> expectedNum(ASCII_MAX, 0);
        for (int i = 0; i < t.size(); ++i) ++expectedNum[t[i]];
        int count = 0, minStart = 0, start = 0, minLen = s.size() + 1;
        for (int i = 0; i < s.size(); ++i) {
            if (++appearedNum[s[i]] <= expectedNum[s[i]]) ++count;
            while (count == t.size()) {
                if (i - start + 1 < minLen) {
                    minLen = i - start + 1;
                    minStart = start;
                }
                if (--appearedNum[s[start]] < expectedNum[s[start]]) --count;
                ++start;
            }
        }
        return minLen == s.size() + 1 ? "" : s.substr(minStart, minLen);
    }
};
