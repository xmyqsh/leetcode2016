class Solution {
public:
    vector<int> hitBricks(vector<vector<int>>& grid, vector<vector<int>>& hits) {
        int m = grid.size(), n = grid[0].size();
        vector<int> result(hits.size(), -1);
        // remove
        for (int k = 0; k != hits.size(); ++k) {
            int x = hits[k][0], y = hits[k][1];
            if (grid[x][y]) grid[x][y] = 0;
            else result[k] = 0;
        }
        DSU dsu(m * n + 1);
        // init
        for (int j = 0; j != n; ++j) if (grid[0][j]) dsu.uNion(m * n, j);
        for (int i = 0; i != m; ++i) {
            for (int j = 0; j != n; ++j) {
                if (grid[i][j]) {
                    if (i != 0 && grid[i - 1][j]) dsu.uNion(i * n + j, (i - 1) * n + j);
                    if (j != 0 && grid[i][j - 1]) dsu.uNion(i * n + j,       i * n + j - 1);
                }
            }
        }
        int blocks = dsu.top();
        // reverse travel
        for (int k = hits.size() - 1; k != -1; --k) {
            int x = hits[k][0], y = hits[k][1];
            if (result[k] == 0) continue;
            grid[x][y] = 1;
            if (x == 0)                       dsu.uNion(x * n + y, m * n);
            if (x != 0 && grid[x - 1][y])     dsu.uNion(x * n + y, (x - 1) * n + y);
            if (x + 1 != m && grid[x + 1][y]) dsu.uNion(x * n + y, (x + 1) * n + y);
            if (y != 0 && grid[x][y - 1])     dsu.uNion(x * n + y, x * n + y - 1);
            if (y + 1 != n && grid[x][y + 1]) dsu.uNion(x * n + y, x * n + y + 1);
            result[k] = max(0, dsu.top() - 1 - blocks);
            blocks = dsu.top();
        }
        return result;
    }
public:
    class DSU {
    public:
        DSU(int n) {
            parent.resize(n); rank.resize(n); count.resize(n);
            iota(parent.begin(), parent.end(), 0);
            fill(rank.begin(), rank.end(), 0);
            fill(count.begin(), count.end(), 1);
        }
        int size(int x) {
            return count[find(x)];
        }
        int top() {
            return size(count.size() - 1) - 1;
        }
        int find(int x) {
            if (x != parent[x]) parent[x] = find(parent[x]);
            return parent[x];
        }
        void uNion(int x, int y) {
            int px = find(x), py = find(y);
            if (px == py) return;
            if (rank[px] < rank[py]) {
                parent[px] = py;
                count[py] += count[px];
            } else if (rank[px] > rank[py]) {
                parent[py] = px;
                count[px] += count[py];
            } else {
                ++rank[px];
                parent[py] = px;
                count[px] += count[py];
            }
        }
    private:
        vector<int> parent, rank, count;
    };
};
