// 39ms
class Solution {
public:
    int longestSubstring(string s, int k) {
        if (k < 2) return s.size();
        vector<vector<int> > count(s.size() + 1, vector<int>(26, 0));
        for (int i = 0; i < s.size(); ++i) {
            for (int c = 0; c < 26; ++c) {
                count[i + 1][c] = count[i][c] + (s[i] == c + 'a' ? 1 : 0);
            }
        }
        int c;
        for (c = 0; c < 26 && (count[s.size()][c] == 0 || count[s.size()][c] >= k); ++c);
        if (c == 26) return s.size();
        int result = 0;
        for (int i = s.size(), j; i > result; --i) {
            if (count[i][s[i - 1] - 'a'] < k) continue;
            for (j = i - 1; j >= 0; --j) {
                int m;
                for (m = j, c = s[m] - 'a'; m <= i - 1 && count[i][c] - count[j][c] >= k; ++m, c = s[m] - 'a');
                if (m == i) result = max(result, i - j);
                else if (count[i][c] < k) {
                    i = m + 1;
                    break;
                }
            }
        }
        return result;
    }
};
