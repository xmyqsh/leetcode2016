// target sequence a1a2...an
// a1 = k / (n - 1)!
// k %= (n - 1)!
// Be aware!
// max(k) = n!, min(k) = 1
class Solution {
public:
    string getPermutation(int n, int k) {
        // make first seq, cnt = n!
        stringstream ss;
        int cnt = 1;
        for (int i = 1; i <= n; ++i) {
            cnt *= i;
            ss << i;
        }
        string s = ss.str();
        int sum, j;
        for (int i = 0; i < n; ++i) {
            // cnt = (n - i - 1)!
            cnt /= n - i;
            // inplace move s[k / (n - i - 1)!] to s[i]
            for (sum = 0, j = 1; i + j <= n; ++j) {
                // Be aware! sum + cnt == k
                if (sum + cnt >= k) break;
                sum += cnt;
                swap(s[i], s[i + j]);
            }
            // Be aware!
            // k = 1 + (k - 1) % (n - i - 1)!
            k -= sum;
        }
        return s;
    }
};

class Solution {
public:
    string getPermutation(int n, int k) {
        stringstream ss;
        for (int i = 1; i != n + 1; ++i) ss << i;
        string seq = ss.str();
        while (--k) next_permutation(seq.begin(), seq.end());
        return seq;
    }
};
