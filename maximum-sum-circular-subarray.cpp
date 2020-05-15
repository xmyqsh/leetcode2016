class Solution {
public:
    int maxSubarraySumCircular(vector<int>& A) {
        int minSum = INT_MAX, minHere = 0, total = 0;
        int maxSum = INT_MIN, maxHere = 0;
        for (auto a : A) {
            total += a;
            minHere = min(minHere + a, a);
            minSum = min(minSum, minHere);
            maxHere = max(maxHere + a, a);
            maxSum = max(maxSum, maxHere);
        }
        return total == minSum ? maxSum : max(maxSum, total - minSum);
    }
};
