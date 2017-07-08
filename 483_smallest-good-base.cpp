class Solution {
public:
    string smallestGoodBase(string n) {
        unsigned long long num = stoll(n);
        for (int m = log((double)num) / log((double)2); m != 1; --m) {
            unsigned long long base = pow(num, 1.0 / m);
            if (myPow(base, m + 1) - 1 == num * (base - 1))
                return to_string(base);
        }
        return to_string(num - 1);
    }
    unsigned long long myPow(unsigned long long base, int m) {
        unsigned long long result = base;
        for (int i = 1; i != m; ++i) result *= base;
        return result;
    }
};

/*
n = 1 + b + b^2 + ... + b^m
n - 1 = b * (1 + b + ... + b^(m - 1))
n - b^m = 1 + b + ... + b^(m - 1)
n - 1 = b * (n - b^m)
(b - 1) * n = b^(m + 1) - 1
n = (b^(m + 1) - 1) / (b - 1)

m = math.log(n, base)
base = math.pow(n, (double)1 / m)
*/
