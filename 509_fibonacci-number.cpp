class Solution {
public:
    int fib(int N) {
        if (N == 0) return 0;
        int pre = 0, cur = 1;
        while (--N) {
            cur += pre;
            pre = cur - pre;
        }
        return cur;
    }
};
