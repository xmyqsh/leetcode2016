class Solution {
public:
    int minDistance(string word1, string word2) {
        if (word1.size() < word2.size()) return minDistance(word2, word1);
        if (word2.empty()) return word1.size();
        vector<int> dp(word2.size() + 1, 0);
        for (int j = 0; j != word2.size(); ++j) dp[j + 1] = j + 1;
        for (int i = 0; i != word1.size(); ++i) {
            int last = dp[0];
            dp[0] = i + 1;
            for (int j = 0; j != word2.size(); ++j) {
                int tmp = dp[j + 1];
                dp[j + 1] = word1[i] == word2[j] ? last : 1 + min(dp[j + 1], dp[j]);
                last = tmp;
            }
        }
        return dp[word2.size()];
    }
};

/*
    s  e  a
  0 1  2  3
e 1 2  1  2
a 2 3  2  1
t 3 4  3  2
*/
