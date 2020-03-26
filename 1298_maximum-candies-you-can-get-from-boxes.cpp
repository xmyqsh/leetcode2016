class Solution {
public:
    int maxCandies(vector<int>& status, vector<int>& candies, vector<vector<int>>& keys, vector<vector<int>>& containedBoxes, vector<int>& initialBoxes) {
        vector<int> visited(keys.size(), 0);
        unordered_set<int> K;
        queue<int> q;
        for (auto n : initialBoxes) q.push(n);
        int ret = 0, failed = 0;
        while (!q.empty()) {
            if (failed == keys.size()) break;
            auto c = q.front(); q.pop();
            if (status[c] == 0 && K.count(c) == 0) {
                q.push(c);
                ++failed;
                continue;
            }
            failed = 0;
            ret += candies[c];
            visited[c] = 1;
            for (auto b : containedBoxes[c]) {
                if (!visited[b]) q.push(b);
            }
            for (auto k : keys[c]) K.insert(k);
        }
        return ret;
    }
};
