class Solution {
public:
    int findKthNumber(int n, int k) {
        int cur = 1;
        k--;
        while (k) {
            long long step = calcStep(n, cur, cur + 1);
            if (step <= k) {
                k -= step;
                cur += 1;
            } else {
                k--;
                cur *= 10;
            }
        }
        return cur;
    }
    long long calcStep(long long n, long long from, long long to) {
        long long step = 0;
        while (from <= n) {
            step += min(n + 1, to) - from;
            from *= 10;
            to *= 10;
        }
        return step;
    }
};
