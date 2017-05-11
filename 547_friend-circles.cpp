class Solution {
public:
    int findCircleNum(vector<vector<int>>& M) {
        int n = M.size();
        par.resize(n);
        for (int i = 0; i != par.size(); ++i)
            par[i] = i;
        result = n;
        for (int i = 0; i != n; ++i)
            for (int j = i + 1; j != n; ++j)
                if (M[i][j] == 1)
                    unite(i, j);
        return result;
    }
    void unite(int x, int y) {
        x = find(x); y = find(y);
        if (x == y) return;
        --result;
        par[x] = y;
    }
    int find(int x) {
        if (x == par[x]) return x;
        return par[x] = find(par[x]);
    }
private:
    vector<int> par;
    int result;
};
