class Solution {
public:
    int minIncrementForUnique(vector<int>& A) {
        if (A.empty()) return 0;
        sort(A.begin(), A.end());
        int cnt = 0;
        for (int i = 1; i != A.size(); ++i) {
            cnt += max(0, A[i - 1] + 1 - A[i]);
            A[i] = max(A[i], A[i - 1] + 1);
        }
        return cnt;
    }
};
