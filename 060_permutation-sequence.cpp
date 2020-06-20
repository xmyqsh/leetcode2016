class Solution {
public:
    string getPermutation(int n, int k) {
        stringstream ss;
        int cnt = 1;
        for (int i = 1; i <= n; ++i) {
            cnt *= i;
            ss << i;
        }
        string s = ss.str();
        int sum, j;
        for (int i = 0; i < n; ++i) {
            cnt /= n - i;
            for (sum = 0, j = 1; i + j <= n; ++j) {
                if (sum + cnt >= k) break;
                sum += cnt;
                swap(s[i], s[i + j]);
            }
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
