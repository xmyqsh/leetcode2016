class Solution {
public:
    int countArrangement(int N) {
        vector<int> num(N + 1);
        for (int i = 1; i <= N; ++i)
            num[i] = i;
        return count(num, N);
    }
    int count(vector<int>& num, int n) {
        if (n == 0) return 1;
        int cnt = 0;
        for (int i = 1; i <= n; ++i) {
            if (!(num[i] % n) || !(n % num[i])) {
                swap(num[i], num[n]);
                cnt += count(num, n - 1);
                swap(num[i], num[n]);
            }
        }
        return cnt;
    }
};
