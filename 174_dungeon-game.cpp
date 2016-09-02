class Solution {
public:
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        int m = dungeon.size(), n = dungeon[0].size();
        vector<int> f(n + 1, INT_MAX);
        for (int i = m - 1; i >= 0; --i) {
            if (i == m - 1) f[n] = 1;
            else f[n] = INT_MAX;
            for (int j = n - 1; j >= 0; --j) {
                const int t = min(f[j], f[j + 1]) - dungeon[i][j];
                f[j] = t <= 0 ? 1 : t;
            }
        }
        return f[0];
    }
};
