// DFS
class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        unordered_map<int, unordered_set<int>> graph;
        vector<int> visited(edges.size() + 1, 0);
        for (const auto& edge : edges) {
            int u = edge[0], v = edge[1];
            if (!graph[u].empty() && !graph[v].empty() && connected(graph, visited, u, v)) return edge;
            graph[u].insert(v);
            graph[v].insert(u);
        }
        return edges.back();
    }
    bool connected(unordered_map<int, unordered_set<int>>& graph, vector<int>& visited, int u, int v) {
        if (u == v) return true;
        visited[u] = 1;
        for (auto n : graph[u]) {
            if (!visited[n] && connected(graph, visited, n, v)) {
                visited[u] = 0;
                return true;
            }
        }
        visited[u] = 0;
        return false;
    }
};

// Union Find
class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        pdsu = new DSU(edges.size() + 1);
        for (const auto& edge : edges) {
            auto u = edge[0], v = edge[1];
            if (pdsu->uNion(u, v)) return edge;
        }
        return edges.back();
    }
private:
    class DSU {
    public:
        DSU(int n) {
            parent.resize(n);
            rank.resize(n);
            iota(parent.begin(), parent.end(), 0);
            fill(rank.begin(), rank.end(), 0);
        }
        int find(int x) {
            if (x != parent[x]) {
                parent[x] = find(parent[x]);
            }
            return parent[x];
        }
        bool uNion(int x, int y) {
            auto px = find(x), py = find(y);
            if (px == py) return true;
            if (rank[px] < rank[py]) parent[px] = py;
            else if (rank[px] > rank[py]) parent[py] = px;
            else {
                parent[py] = px;
                ++rank[px];
            }
            return false;
        }
    private:
        vector<int> parent;
        vector<int> rank;
    };
private:
    DSU* pdsu;
};
