class Solution {
public:
    int largestPerimeter(vector<int>& A) {
        sort(A.begin(), A.end());
        int ret = 0;
        for (int i = A.size() - 1; i - 2 != -1; --i) {
            if (A[i] < A[i - 1] + A[i - 2]) { ret = A[i] + A[i - 1] + A[i - 2]; break; }
        }
        return ret;
    }
};
