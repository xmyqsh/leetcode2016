class Solution {
public:
    bool isScramble(string s1, string s2) {
        if (s1.size() != s2.size()) return false;
        if (s1.empty()) return true;
        if (s1.size() == 1) return s1[0] == s2[0];
        vector<vector<vector<bool> > > dp(s1.size(), vector<vector<bool> >(s1.size(), vector<bool>(s1.size() + 1, false)));
        for (int i = s1.size() - 1; i >= 0; --i) {
            for (int j = s2.size() - 1; j >= 0; --j) {
                dp[i][j][1] = s1[i] == s2[j];
                for (int l = 2; i + l <= s1.size() && j + l <= s2.size(); ++l) {
                    for (int n = 1; n < l && !dp[i][j][l]; ++n) {
                        dp[i][j][l] = dp[i][j][l] | (dp[i][j][n] && dp[i + n][j + n][l - n]);
                        dp[i][j][l] = dp[i][j][l] | (dp[i][j + l - n][n] && dp[i + n][j][l - n]);
                    }
                }
            }
        }
        return dp[0][0][s1.size()];
    }
};
// recursive + pruning
class Solution {
private:
    typedef string::iterator Iterator;
public:
    bool isScramble(string s1, string s2) {
        if (s1.size() != s2.size()) return false;
        if (s1.empty()) return true;
        return isScramble(s1.begin(), s1.end(), s2.begin());
    }
private:
    bool isScramble(Iterator first1, Iterator last1, Iterator first2) {
        auto length = distance(first1, last1);
        auto last2 = next(first2, length);
        if (length == 1) return *first1 == *first2;
        auto tmp1 = first1, tmp2 = first2;
        vector<int> count(26, 0);
        for (int i = 0; i < length; ++i)
            count[*tmp1++ - 'a']++, count[*tmp2++ - 'a']--;
        for (int i = 0; i < 26; ++i) if (count[i]) return false;
        for (int i = 1; i < length; ++i) {
            if ((isScramble(first1, first1 + i, first2) && isScramble(first1 + i, last1, first2 + i)) || 
                (isScramble(first1, first1 + i, last2 - i) && isScramble(first1 + i, last1, first2)))
                return true;
        }
        return false;
    }
};
