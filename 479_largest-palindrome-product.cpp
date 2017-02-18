class Solution {
public:
    int largestPalindrome(int n) {
        if (n == 1) return 9;
        int MOD = 1337;
        int mod = pow(10, n);
        int max = mod - 1;
        long long product = (long long)max * max;
        int left = product / mod;
        int right = product % mod;
        if (left == reverseNum(right, n)) return product % MOD;
        if (left > right) --left;
        product = (long long)mod * left + reverseNum(left, n);
        while (left != mod / 10) {
            for (int i = max; i > product / i; --i)
                if (product % i == 0) return product % MOD;
            --left;
            product = (long long)mod * left + reverseNum(left, n); 
        }
        return product % MOD;
    }
    int reverseNum(int num, int n) {
        int ret = 0;
        int base = pow(10, n - 1);
        while (num) {
            ret += (num % 10) * base;
            base /= 10;
            num /= 10;
        }
        return ret;
    }
};
