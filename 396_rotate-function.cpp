class Solution {
public:
    int maxRotateFunction(vector<int>& A) {
        int sum = 0, result = 0, F = 0;
        for (int i = 0; i != A.size(); ++i) {
            sum += A[i];
            F += i * A[i];
        }
        result = F;
        for (int i = A.size() - 1; i > 0; --i) {
            F += sum - A.size() * A[i];
            result = max(result, F);
        }
        return result;
    }
};
