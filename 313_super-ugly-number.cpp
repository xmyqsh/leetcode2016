class Solution {
public:
    int nthSuperUglyNumber(int n, vector<int>& primes) {
        vector<int> f(n, 1);
        auto cmp = [](const tuple<int, int, int>& p1, const tuple<int, int, int>& p2) {
            return get<0>(p1) > get<0>(p2);
        };
        priority_queue<tuple<int, int, int>, vector<tuple<int, int, int> >, decltype(cmp)> minHeap(cmp);
        for (int i = 0; i != primes.size(); ++i) minHeap.emplace(primes[i], i, 0);
        for (int i = 1; i < n; ++i) {
            auto myTuple = minHeap.top(); minHeap.pop();
            f[i] = get<0>(myTuple);
            int idx = get<2>(myTuple) + 1;
            minHeap.emplace(f[idx] * primes[get<1>(myTuple)], get<1>(myTuple), idx);
            while (get<0>(minHeap.top()) == f[i]) {
                auto myTuple = minHeap.top(); minHeap.pop();
                int idx = get<2>(myTuple) + 1;
                minHeap.emplace(f[idx] * primes[get<1>(myTuple)], get<1>(myTuple), idx);
            }
        }
        return f[n - 1];
    }
};
