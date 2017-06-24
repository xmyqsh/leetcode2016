class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> cnt(26, 0);
        for (auto task : tasks) ++cnt[task - 'A'];
        auto cmp = [](const pair<int, int>& p1, const pair<int, int>& p2) {
            return p1.second < p2.second;
        };
        priority_queue<pair<int, int>, vector<pair<int, int> >, decltype(cmp)> pq(cmp);
        for (int i = 0; i != 26; ++i)
            if (cnt[i]) pq.push({i, cnt[i]});
        
        int result = tasks.size();
        while (!pq.empty()) {
            vector<pair<int, int> > taskConsumed;
            int remain = n + 1;
            while (remain && !pq.empty()) {
                auto p = pq.top(); pq.pop();
                if (--p.second > 0) taskConsumed.push_back(p);
                --remain;
            }
            if (!taskConsumed.empty()) {
                result += remain;
                for (auto task : taskConsumed) pq.push(task);
            }
        }
        return result;
    }
};
