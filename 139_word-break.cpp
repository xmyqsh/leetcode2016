class Solution {
public:
    bool wordBreak(string s, unordered_set<string>& wordDict) {
        vector<bool> f(s.size() + 1, false);
        f[0] = true;
        int minLen = INT_MAX, maxLen = INT_MIN;
        for (auto word : wordDict) {
            minLen = min(minLen, (int)word.length());
            maxLen = max(maxLen, (int)word.length());
        }
        for (int i = 1; i <= s.size(); ++i) {
            for (int j = minLen, pos = i - minLen; j <= maxLen && pos >= 0; ++j, --pos) {
                if (f[pos] && wordDict.count(s.substr(pos, j))) {
                    f[i] = true;
                    break;
                }
            }
        }
        return f[s.size()];
    }
};
