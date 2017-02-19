class Solution {
public:
    int longestPalindrome(string s) {
        unordered_map<char, int> mp;
        for (auto c : s) ++mp[c];
        int ret = 0;
        bool one = false;
        for (auto &iter : mp) {
            if (iter.second % 2) {
                one = true;
                ret += iter.second - 1;
            } else {
                ret += iter.second;
            }
        }
        return one ? ret + 1 : ret;
    }
};
