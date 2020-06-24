// Same as solution 3
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

// A straight forword solution
class Solution {
public:
    int minSteps(int n) {
        vector<int> dp(n + 1, INT_MAX); dp[1] = 0;
        for (int i = 2; i != n + 1; ++i) {
            //for (int j = i - 1; j != 0; --j) {
            for (int j = i / 2; j != 0; --j) {
                if ((i - j) % j == 0) dp[i] = min(dp[i], dp[j] + 1 + (i - j) / j);
            }
        }
        return dp[n];
    }
};

/*
3:  A --> AA --> AAA                                                                    A
7:  A --> AA --> AAA --> AAAA --> AAAAA --> AAAAAA --> AAAAAAA                          A
10: A --> AA --> AAAA --> AAAAAA --> AAAAAAAA --> AAAAAAAAAA                            AA
24: A --> AA --> AAAA --> AAAAAAAA --> AAAAAAAAAAAAAAAA --> AAAAAAAAAAAAAAAAAAAAAAAA    AAAAAAAA
*/

// Same as solution 1
class Solution {
public:
    int minSteps(int n) {
        // [CPP][CPPPP][CP] <<-->> len1 * len2 * len3 = n  ---> op = len1 + len2 + len3
        int d = 2, cnt = 0;
        while (n != 1) {
            while (n % d == 0) {
                cnt += d;
                n /= d;
            }
            ++d;
        }
        return cnt;
    }
};
