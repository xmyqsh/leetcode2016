class Solution {
public:
    int minDistance(string word1, string word2) {
        if (word1.size() < word2.size())
            return minDistance(word2, word1);
        if (word2.empty()) return word1.size();
        vector<int> dp(word2.size() + 1, 0);
        for (int i = 0; i <= word1.size(); ++i) {
            int last;
            for (int j = 0; j <= word2.size(); ++j) {
                if (i == 0) dp[j] = j;
                else if (j == 0) {
                    last = dp[0];
                    dp[0] = i;
                } else {
                    int tmp = dp[j];
                    dp[j] = word1[i - 1] == word2[j - 1] ? last : 1 + min(last, min(dp[j - 1], dp[j]));
                    last = tmp;
                }
            }
        }
        return dp[word2.size()];
    }
};
