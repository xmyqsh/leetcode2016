class Solution {
public:
    bool isMatch(string s, string p) {
        if (p.empty()) return s.empty();
        if (p.size() > 1 && p[1] == '*')
            return isMatch(s, p.substr(2)) || !s.empty() && (p[0] == '.' || p[0] == s[0]) && isMatch(s.substr(1), p);
        else
            return !s.empty() && (p[0] == '.' || p[0] == s[0]) && isMatch(s.substr(1), p.substr(1));
    }
};

class Solution {
public:
    bool isMatch(string s, string p) {
        vector<vector<bool>> dp(s.size() + 1, vector<bool>(p.size() + 1, false));
        dp[0][0] = true;
        for (int j = 1; j < p.size(); ++j) dp[0][j + 1] = p[j] == '*' && dp[0][j - 1];
        for (int i = 0; i != s.size(); ++i) {
            for (int j = 0; j != p.size(); ++j) {
                if (s[i] == p[j] || '.' == p[j]) dp[i + 1][j + 1] = dp[i][j];
                else if (p[j] == '*') {
                    //assert(j != 0);
                    if (s[i] == p[j - 1] || '.' == p[j - 1]) {
                        //                      match 0          match 1   match multi
                        dp[i + 1][j + 1] = (dp[i + 1][j - 1] || dp[i][j] || dp[i][j + 1]);
                    }   //                                              s[i - 1] <--> p[j] = '*'
                    else dp[i + 1][j + 1] = dp[i + 1][j - 1]; // match 0
                }
            }
        }
        return dp[s.size()][p.size()];
    }
};
