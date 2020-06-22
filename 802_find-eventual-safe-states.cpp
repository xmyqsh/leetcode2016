class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        vector<int> terminal(graph.size(), -2);
        vector<int> result;
        for (int i = 0; i != graph.size(); ++i) {
            if (dfs(terminal, graph, i) != -1) result.push_back(i);
        }
        return result;
    }
    int dfs(vector<int>& terminal, const vector<vector<int>>& graph, int i) {
        if (terminal[i] == -3) {
            terminal[i] = -1;
            return terminal[i];
        }
        if (terminal[i] != -2) return terminal[i];
        terminal[i] = -3;
        int tmp = i;
        for (auto n : graph[i]) {
            tmp = dfs(terminal, graph, n);
            if (tmp == -1) break;
        }
        terminal[i] = tmp;
        return terminal[i];
    }
};
