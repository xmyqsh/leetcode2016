class Solution {
public:
    int minDeletionSize(vector<string>& A) {
        int n = A[0].size();
        int ret = 0;
        vector<bool> cared(A.size(), true);    // The key
        for (int j = 0; j != n; ++j) {
            int i;
            for (i = 1; i != A.size(); ++i) {
                if (!cared[i]) continue;
                if (A[i - 1][j] > A[i][j]) {
                    ++ret;
                    break;
                }
            }
            if (i != A.size()) continue;
            for (i = 1; i != A.size(); ++i) {
                if (!cared[i]) continue;
                if (A[i - 1][j] < A[i][j]) {
                    cared[i] = false;
                }
            }
        }
        return ret;
    }
};
