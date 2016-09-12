class Solution {
public:
    int climbStairs(int n) {
        int prev = 1, cur = 1;
        while (--n) {
            cur += prev;
            prev = cur - prev;
        }
        return cur;
    }
};
