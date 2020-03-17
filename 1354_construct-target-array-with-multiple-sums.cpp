// Count + Priority Queue
// O(10^9 * log(L))
// Time Limit Exceed
// Bad Case: [1, 1000000000]
// TODO: Optimize this
class Solution {
public:
    bool isPossible(vector<int>& target) {
        priority_queue<int> pq;
        int sum = 0;
        for (auto n : target) {
            pq.push(n);
            sum += n;
        }
        while (pq.top() != 1) {
            auto n = pq.top(); pq.pop();
            auto remain_sum = sum - n;
            if (remain_sum >= n) return false;
            pq.push(n - remain_sum);
            sum = n;
        }
        return true;
    }
};
