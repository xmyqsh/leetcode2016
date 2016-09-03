class Solution {
public:
    int countPrimes(int n) {
        vector<int> isPrime(n, 1);
        int i, count = 0;
        for (i = 2; i * i < n; ++i) {
            if (!isPrime[i]) continue;
            ++count;
            for (int j = i * i; j < n; j += i) isPrime[j] = 0;
        }
        for (; i < n; ++i) if (isPrime[i]) ++count;
        return count;
    }
};
