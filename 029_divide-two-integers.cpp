class Solution {
public:
    int divide(int dividend, int divisor) {
        if (divisor == 0 || dividend == INT_MIN && divisor == -1)
            return INT_MAX;
        int result = 0;
        long long ldividend = labs(dividend), ldivisor = labs(divisor);
        while (ldividend >= ldivisor) {
            long long tmp = ldivisor, mul = 1;
            while (ldividend >= (tmp << 1)) {
                tmp <<= 1;
                mul <<= 1;
            }
            ldividend -= tmp;
            result += mul;
        }
        return ((dividend ^ divisor) >> 31) ? -result : result;
    }
};
