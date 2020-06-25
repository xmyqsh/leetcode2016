class Solution {
public:
    int regionsBySlashes(vector<string>& grid) {
        int m = grid.size(), n = grid[0].size();
        DSU dsu(m * n * 4);
        for (int i = 0; i != m; ++i) {
            for (int j = 0; j != n; ++j) {
                // intra grid union
                if (i + 1 != m) dsu.uNion( idxDown(m, n, i, j),   idxUp(m, n, i + 1, j));
                if (j + 1 != n) dsu.uNion(idxRight(m, n, i, j), idxLeft(m, n, i, j + 1));
                // inner grid union
                if (grid[i][j] == '/') {
                    dsu.uNion( idxLeft(m, n, i, j),   idxUp(m, n, i, j));
                    dsu.uNion(idxRight(m, n, i, j), idxDown(m, n, i, j));
                } else if (grid[i][j] == '\\') {
                    dsu.uNion( idxLeft(m, n, i, j), idxDown(m, n, i, j));
                    dsu.uNion(idxRight(m, n, i, j),   idxUp(m, n, i, j));
                } else {
                    dsu.uNion( idxLeft(m, n, i, j),   idxUp(m, n, i, j));
                    dsu.uNion(idxRight(m, n, i, j), idxDown(m, n, i, j));
                    dsu.uNion( idxLeft(m, n, i, j), idxDown(m, n, i, j));
                }
            }
        }
        unordered_set<int> st;
        for (int i = 0; i != m * n * 4; ++i) st.insert(dsu.find(i));
        return st.size();
    }
    int idxLeft(int m, int n, int x, int y) {
        return (x * n + y) * 4;
    }
    int idxUp(int m, int n, int x, int y) {
        return (x * n + y) * 4 + 1;
    }
    int idxRight(int m, int n, int x, int y) {
        return (x * n + y) * 4 + 2;
    }
    int idxDown(int m, int n, int x, int y) {
        return (x * n + y) * 4 + 3;
    }
public:
    class DSU {
    public:
        DSU(int n) {
            parent.resize(n); rank.resize(n);
            iota(parent.begin(), parent.end(), 0);
            fill(rank.begin(), rank.end(), 0);
        }
        int find(int x) {
            if (x != parent[x]) parent[x] = find(parent[x]);
            return parent[x];
        }
        void uNion(int x, int y) {
            int px = find(x), py = find(y);
            if (px == py) return;
            if (rank[px] < rank[py]) parent[px] = py;
            else if (rank[px] > rank[py]) parent[py] = px;
            else { ++rank[px]; parent[py] = px; }
        }
    private:
        vector<int> parent, rank;
    };
};
/*
 —— —— —— ——
| \  /  \ / |
| /  \  / \ |
| \  /  \ / |
| /  \  / \ |
 —— —— —— ——
   1     5     9
 0   2 4   6 8   10
   3     7     11
   13    17    21
 12 14 16 18 20  22
   15   19     23
*/
