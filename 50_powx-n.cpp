class Solution {
public:
    double myPow(double x, int n) {
        if (x == 0) return 0;
        if (n == 0) return 1;
        double tmp = abs(n) % 2 ? (x < 0 ? -1 : 1) * subPow(fabs(x), abs(n)) : subPow(fabs(x), abs(n));
        return n < 0 ? 1 / tmp : tmp;
    }
    double subPow(double x, int n) {
        if (n == 0) return 1;
        if (n == 1) return x;
        double tmp = subPow(x, n / 2);
        if (n % 2) return x * tmp * tmp;
        else return tmp * tmp;
    }
};
