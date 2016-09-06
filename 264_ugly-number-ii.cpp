class Solution {
public:
    int nthUglyNumber(int n) {
        vector<int> f(n, 1);
        int f2 = 2, f3 = 3, f5 = 5;
        int idx2 = 0, idx3 = 0, idx5 = 0;
        for (int i = 1; i < n; ++i) {
            int minV = min(f2, min(f3, f5));
            f[i] = minV;
            if (minV == f2) f2 = 2 * f[++idx2];
            if (minV == f3) f3 = 3 * f[++idx3];
            if (minV == f5) f5 = 5 * f[++idx5];
        }
        return f[n - 1];
    }
};
