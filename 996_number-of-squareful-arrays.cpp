// count by enumerating permutation, TLE
class Solution {
public:
    int numSquarefulPerms(vector<int>& A) {
        int cnt = 0;
        numSquarefulPerms(A, 0, cnt);
        return cnt;
    }
    void numSquarefulPerms(vector<int> A, int cur, int& cnt) {
        if (cur + 1 == A.size()) {
            if (squarefull(A)) ++cnt;
            return;
        }
        for (int i = cur; i != A.size(); ++i) {
            if (i != cur && A[i] == A[cur]) continue;
            swap(A[i], A[cur]);
            numSquarefulPerms(A, cur + 1, cnt);
        }
    }
    bool squarefull(const vector<int>& A) {
        for (int i = 0; i + 1 < A.size(); ++i) {
            int sum = A[i] + A[i + 1];
            if (pow((int)sqrt(sum), 2) != sum) return false;
        }
        return true;
    }
};

// count by enumerating hamiltonian path(state could be cached further), TLE
class Solution {
public:
    int numSquarefulPerms(vector<int>& A) {
        unordered_map<int, int> count;
        unordered_map<int, unordered_set<int>> graph;
        for (int i = 0; i != A.size(); ++i) {
            ++count[A[i]];
            for (int j = i + 1; j != A.size(); ++j) {
                int sum = A[i] + A[j];
                if (pow((int)sqrt(sum), 2) != sum) continue;
                graph[i].insert(j);
                graph[j].insert(i);
            }
        }
        vector<int> visited(A.size(), 0);
        int ret = 0;
        for (int i = 0; i != A.size(); ++i) {
            visited[i] = 1;
            dfs(graph, visited, i, 1, A.size(), ret);
            visited[i] = 0;
        }
        for (const auto& item : count) {
            for (int i = item.second; i != 1; --i) ret /= i;
        }
        return ret;
    }
    void dfs(unordered_map<int, unordered_set<int>>& graph,
             vector<int>& visited, int i, int cnt, int n, int& ret) {
        if (cnt == n) {
            ++ret;
            return;
        }
        for (auto j : graph[i]) {
            if (visited[j]) continue;
            visited[j] = 1;
            dfs(graph, visited, j, cnt + 1, n, ret);
            visited[j] = 0;
        }
    }
};

// count by compact hamiltonian path(state cannot by cached), AC
class Solution {
public:
    int numSquarefulPerms(vector<int>& A) {
        unordered_map<int, int> count;
        for (auto a : A) ++count[a];
        unordered_map<int, vector<int>> graph;
        for (const auto& itemX : count) {
            for (const auto& itemY : count) {
                int sum = itemX.first + itemY.first;
                if (pow((int)sqrt(sum), 2) != sum) continue;
                graph[itemX.first].push_back(itemY.first);
            }
        }
        int ret = 0;
        for (auto& item : count) {
            --item.second;
            dfs(graph, count, item.first, 1, A.size(), ret);
            ++item.second;
        }
        return ret;
    }
    void dfs(unordered_map<int, vector<int>>& graph,
             unordered_map<int, int>& count, int u, int cnt, int n, int& ret) {
        if (cnt == n) {
            ++ret;
            return;
        }
        for (auto v : graph[u]) {
            if (count[v] == 0) continue;
            --count[v];
            dfs(graph, count, v, cnt + 1, n, ret);
            ++count[v];
        }
    }
};

// count by enumerating hamiltonian path with cache, AC
// design and use cache carefully here. Or some evil will hide in it.
// 1. N distinct cache needed here.
// 2. 2D cache needed here.
class Solution {
public:
    int numSquarefulPerms(vector<int>& A) {
        unordered_map<int, int> count;
        unordered_map<int, unordered_set<int>> graph;
        for (int i = 0; i != A.size(); ++i) {
            ++count[A[i]];
            for (int j = i + 1; j != A.size(); ++j) {
                int sum = A[i] + A[j];
                if (pow((int)sqrt(sum), 2) != sum) continue;
                graph[i].insert(j);
                graph[j].insert(i);
            }
        }
        unsigned int visited = 0;
        int ret = 0;
        for (unsigned int i = 0, mask = 1; i != A.size(); ++i, mask <<= 1) {
            unordered_map<unsigned int, unordered_map<int, int>> cache;
            visited |= mask;
            ret += dfs(graph, cache, visited, i, 1, A.size());
            visited &= ~mask;
        }
        for (const auto& item : count) {
            for (int i = item.second; i != 1; --i) ret /= i;
        }
        return ret;
    }
    int dfs(unordered_map<int, unordered_set<int>>& graph,
            unordered_map<unsigned int, unordered_map<int, int>>& cache,
            unsigned int& visited, int i, int cnt, int n) {
        if (cnt == n) return 1;
        if (cache[visited].count(i)) return cache[visited][i];
        int ret = 0;
        for (auto j : graph[i]) {
            unsigned int mask = (1 << j);
            if (visited & mask) continue;
            visited |= mask;
            ret += dfs(graph, cache, visited, j, cnt + 1, n);
            visited &= ~mask;
        }
        cache[visited][i] = ret;
        return cache[visited][i];
    }
};
