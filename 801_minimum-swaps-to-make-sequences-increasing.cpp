class Solution {
public:
    int minSwap(vector<int>& A, vector<int>& B) {
        vector<int> stay(A.size(), INT_MAX), change(A.size(), INT_MAX);
        stay[0] = 0; change[0] = 1;
        for (int i = 1; i != A.size(); ++i) {
            if (A[i - 1] < A[i] && B[i - 1] < B[i]) {
                stay[i] = min(stay[i], stay[i - 1]);
                change[i] = min(change[i], 1 + change[i - 1]);
            }
            if (A[i - 1] < B[i] && B[i - 1] < A[i]) {
                stay[i] = min(stay[i], change[i - 1]);
                change[i] = min(change[i], 1 + stay[i - 1]);
            }
        }
        return min(stay[A.size() - 1], change[A.size() - 1]);
    }
};
