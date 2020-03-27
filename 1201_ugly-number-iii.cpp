class Solution {
public:
    int nthUglyNumber(int n, int a, int b, int c) {
        int L = 1, R = 2000000005;
        auto lcm = [](long long a, long long b) {
            return a * b / __gcd(a, b);
        };
        auto lab = lcm(a, b);
        auto lbc = lcm(b, c);
        auto lac = lcm(a, c);
        auto labc = lcm(lab, c);
        auto idx = [&](int m) {
            return m / a + m / b + m / c - m / lab - m / lbc - m / lac + m / labc;
        };
        while (L != R) {                                // The lower bound guarantees the solution is valid!!!
            const int m = L + (R - L) / 2;
            if (idx(m) < n) L = m + 1;
            else R = m;
        }
        return R;
    }
};
