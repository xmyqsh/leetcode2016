class Solution {
public:
    int numTrees(int n) {
        if (n == 0) return 0;
        vector<int> f(n + 1, 0);
        f[0] = 1, f[1] = 1, f[2] = 2;
        for (int i = 3; i <= n; ++i)
            for (int k = 0; k < i; ++k)
                f[i] += f[k] * f[i - k - 1];
        return f[n];
    }
};
