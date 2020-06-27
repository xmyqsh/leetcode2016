class Solution {
public:
    int removeStones(vector<vector<int>>& stones) {
        unordered_map<int, vector<int>> row, col;
        for (int i = 0; i != stones.size(); ++i) {
            row[stones[i][0]].push_back(i);
            col[stones[i][1]].push_back(i);
        }
        unordered_map<int, int> hash2id;
        DSU dsu(stones.size());
        for (const auto& item : row) {
            const auto& conn = item.second;
            int prevHash = hash(stones[conn[0]]);
            if (!hash2id.count(prevHash)) {
                hash2id[prevHash] = hash2id.size();
            }
            for (int k = 1; k != conn.size(); ++k) {
                int curHash = hash(stones[conn[k]]);
                if (!hash2id.count(curHash)) {
                    hash2id[curHash] = hash2id.size();
                }
                dsu.uNion(hash2id[prevHash], hash2id[curHash]);
                prevHash = curHash;
            }
        }
        for (const auto& item : col) {
            const auto& conn = item.second;
            int prevHash = hash(stones[conn[0]]);
            if (!hash2id.count(prevHash)) {
                hash2id[prevHash] = hash2id.size();
            }
            for (int k = 1; k != conn.size(); ++k) {
                int curHash = hash(stones[conn[k]]);
                if (!hash2id.count(curHash)) {
                    hash2id[curHash] = hash2id.size();
                }
                dsu.uNion(hash2id[prevHash], hash2id[curHash]);
                prevHash = curHash;
            }
        }
        unordered_set<int> st;
        for (const auto& item : hash2id) st.insert(dsu.find(item.second));
        return stones.size() - st.size();
    }
    int hash(const vector<int>& stone) {
        return stone[0] * 10000 + stone[1];
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
            else {
                ++rank[px];
                parent[py] = px;
            }
        }
    private:
        vector<int> parent, rank;
    };
};
