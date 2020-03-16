// 滑动窗口：O(2N)
class Solution {
public:
    int numberOfSubstrings(string s) {
        vector<int> cnt(3, 0);
        int ret = 0, b = 0;
        for (int i = 0; i != s.size(); ++i) {
            ++cnt[s[i] - 'a'];
            while (cnt[0] && cnt[1] && cnt[2]) {
                --cnt[s[b++] - 'a'];
            }
            ret += b;
        }
        return ret;
    }
};

// 动态规划：O(N)
class Solution {
public:
    int numberOfSubstrings(string s) {
        int n = s.size();
        vector<int> dp(3, -1);
        int ret = 0;
        for (int i = 0; i != n; ++i) {
            dp[s[i] - 'a'] = i;
            int b = min(dp[0], min(dp[1], dp[2]));
            if (b != -1) {
                ret += b + 1;
            }
        }
        return ret;
    }
};
