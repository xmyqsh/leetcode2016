class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int result;
        auto cmp = [&matrix](const pair<int, int>& p1, const pair<int, int>& p2) {
            return matrix[p1.first][p1.second] > matrix[p2.first][p2.second];
        };
        priority_queue<pair<int, int>, vector<pair<int, int> >,  decltype(cmp)> minHeap(cmp);
        minHeap.emplace(0, 0);
        while (--k) {
            auto pairIdx = minHeap.top(); minHeap.pop();
            if (pairIdx.first + 1 != matrix.size()) minHeap.emplace(pairIdx.first + 1, pairIdx.second);
            if (pairIdx.first == 0 && pairIdx.second + 1 != matrix[0].size())
                minHeap.emplace(pairIdx.first, pairIdx.second + 1);
        }
        return matrix[minHeap.top().first][minHeap.top().second];
    }
};
