// Count + Priority Queue
// O(ElogL)
class Solution {
public:
    int maxEvents(vector<vector<int>>& events) {
        unordered_map<int, vector<int>> mp;
        int maxEnd = -1;
        for (const auto& e : events) {
            mp[e[0]].push_back(e[1]);
            maxEnd = max(maxEnd, e[1]);
        }
        int cnt = 0;
        priority_queue<int, vector<int>, greater<int>> pq;
        for (int i = 1; i != maxEnd + 1; ++i) {
            for (auto e : mp[i]) pq.push(e);
            while (!pq.empty() && pq.top() < i) pq.pop();
            if (!pq.empty()) {
                pq.pop();
                ++cnt;
            }
        }
        return cnt;
    }
};
