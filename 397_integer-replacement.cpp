class Solution {
public:
    int integerReplacement(int n) {
        return calc(n);
    }
    int calc(long n) {
        if (n == 1) return 0;
        if (cache.count(n)) return cache[n];
        if ((n & 1)) cache[n] = 1 + min(calc(n - 1), calc(n + 1));
        else cache[n] = 1 + calc(n / 2);
        return cache[n];
    }
private:
    unordered_map<long, int> cache;
};
