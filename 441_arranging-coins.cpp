class Solution {
public:
    int arrangeCoins(int n) {
        int ret = 0, cur = 1;
        while (n >= cur) {
            n -= cur++;
            ++ret;
        }
        return ret;
    }
};
