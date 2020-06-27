class Solution {
public:
    int minDeletionSize(vector<string>& A) {
        int cnt = 0;
        for (int j = 0, i; j != A[0].size(); ++j) {
            for (i = 1; i != A.size(); ++i) {
                if (A[i - 1][j] > A[i][j]) {
                    ++cnt;
                    break;
                }
            }
        }
        return cnt;
    }
};
