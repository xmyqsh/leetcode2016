class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<pair<int, int>>& edges) {
        if (n == 1) return vector<int>(1, 0);
        vector<unordered_set<int> > adj(n);
        for (auto edge : edges) {
            adj[edge.first].insert(edge.second);
            adj[edge.second].insert(edge.first);
        }
        vector<int> leaves, newLeaves;
        for (int i = 0; i < n; ++i) if (adj[i].size() == 1) newLeaves.push_back(i);
        do {
            swap(leaves, newLeaves);
            newLeaves.clear();
            for (auto leave : leaves) {
                for (auto neighbor : adj[leave]) {
                    adj[neighbor].erase(leave);
                    if (adj[neighbor].size() == 1) newLeaves.push_back(neighbor);
                }
            }
        } while (!newLeaves.empty());
        return leaves;
    }
};
