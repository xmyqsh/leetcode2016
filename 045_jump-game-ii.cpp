class Solution {
public:
    int jump(vector<int> A) {
        if (A.size() < 2) return 0;
        int j = 1, maxInd = j, cnt = 0;
        for (int i = 0; A[i] + i < A.size() - 1;) {
            for (; j <= A[i] + i; ++j)
                maxInd = (A[maxInd] + maxInd <= A[j] + j) ? j : maxInd;
            ++cnt;
            i = maxInd;
        }
        return ++cnt;
    }
};
