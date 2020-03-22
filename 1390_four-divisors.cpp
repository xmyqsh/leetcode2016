class Solution {
public:
    int sumFourDivisors(vector<int>& nums) {
        int ret = 0;
        for (auto n : nums) {
            int s = sqrt(n);
            if (s * s == n) continue;
            int cnt = 0;
            int cur = 0;
            for (int d = 2; d <= s; ++d) {
                if (n % d == 0) {
                    ++cnt;
                    cur += d + n / d;
                }
                if (cnt == 2) break;
            }
            if (cnt == 1) {
                //cout << n << endl;
                ret += cur + 1 + n;
            }
        }
        return ret;
        /*
        int n = 100005 / 2;
        vector<int> isPrime(n, 1);
        vector<int> primes;
        int i;
        for (i = 2; i * i < n; ++i) {
            if (!isPrime[i]) continue;
            primes.push_back(i);
            for (int j = i * i; j < n; j += i) isPrime[j] = 0;
        }
        for (; i < n; ++i) if (isPrime[i]) primes.push_back(i);
        //return primes.size();
        int ret = 0;
        unordered_map<int, int> mp;
        for (auto n : nums) ++mp[n];
        for (int i = 0; i != primes.size(); ++i) {
            for (int j = i + 1; j != primes.size(); ++j) {
                long long target = (long long)primes[i] * primes[j];
                if (target > 100005) break;
                if (mp.count(target)) {
                    ret += mp[target] * (1 + primes[i] + primes[j] + target);
                }
            }
        }
        return ret;
        */
    }
};

/*
[1,2,3,4,5,6,7,8,9,10]
6    ---> 1 + 2 + 3 + 6  = 12
10   ---> 1 + 2 + 5 + 10 = 18

8    ---> 1 + 2 + 4 + 8  = 15
*/
