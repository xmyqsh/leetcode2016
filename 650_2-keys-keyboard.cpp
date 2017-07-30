class Solution {
public:
    int minSteps(int n) {
        vector<int> primes;
        vector<bool> isPrime(1000, true);
        for (int i = 2; i != 1000; ++i) {
            if (isPrime[i]) {
                primes.push_back(i);
                for (int j = 2; i * j < 1000; ++j)
                    isPrime[i * j] = false;
            }
        }
        unordered_map<int, int> mp;
        for (auto prime : primes) {
            int cnt = 0;
            while (n != 1 && !(n % prime)) {
                n /= prime;
                ++cnt;
            }
            if (cnt) mp[prime] = cnt;
        }
        int result = 0;
        for (auto& item : mp) {
            result += item.first * item.second;
        }
        return result;
    }
};
