class Solution {
public:
    int maxPerformance(int n, vector<int>& speed, vector<int>& efficiency, int k) {
        vector<int> idx(n);
        iota(idx.begin(), idx.end(), 0);
        sort(idx.begin(), idx.end(), [&](int id1, int id2) {
            return efficiency[id1] > efficiency[id2];
        });
        priority_queue<int, vector<int>, greater<int>> pq;
        long long sum = 0, ret = 0;
        for (auto id : idx) {
            pq.push(speed[id]);
            sum += speed[id];
            ret = max(ret, sum * efficiency[id]);
            if (pq.size() == k) {
                sum -= pq.top(); pq.pop();
            }
        }
        return (ret % 1000000007);
    }
};
