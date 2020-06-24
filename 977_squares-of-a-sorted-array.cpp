class Solution {
public:
    vector<int> sortedSquares(vector<int>& A) {
        vector<int> S(A.size());
        int i, j, k;
        for (i = 0; i != A.size() && A[i] <= 0; ++i);
        for (k = i - 1, j = 0; k != -1 && i != A.size();) {
            if (A[k] + A[i] > 0) S[j++] = A[k] * A[k--];
            else S[j++] = A[i] * A[i++];
        }
        for (; k != -1; --k, ++j) S[j] = A[k] * A[k];
        for (; i != A.size(); ++i, ++j) S[j] = A[i] * A[i];
        return S;
    }
};
