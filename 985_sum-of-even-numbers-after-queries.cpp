class Solution {
public:
    vector<int> sumEvenAfterQueries(vector<int>& A, vector<vector<int>>& queries) {
        int sum = 0;
        for (auto a : A) if ((a & 1) == 0)sum += a;
        vector<int> result;
        for (const auto& q : queries) {
            auto i = q[1], v = q[0];
            if (A[i] & 1) {
                if (v & 1) sum += A[i] + v;
            } else {
                if (v & 1) sum -= A[i];
                else sum += v;
            }
            A[i] += v;
            result.push_back(sum);
        }
        return result;
    }
};
