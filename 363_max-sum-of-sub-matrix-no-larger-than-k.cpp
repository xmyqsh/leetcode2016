class Solution {
public:
    int maxSumSubmatrix(vector<vector<int>>& matrix, int k) {
        if (matrix.empty() || matrix[0].empty()) return 0;
        int row = matrix.size(), col = matrix[0].size(), ret = INT_MIN;
        if (row < col) {
            for (int u = 0; u < row; ++u) {
                vector<int> sums(col, 0);
                for (int b = u; b < row; ++b) {
                    for (int i = 0; i < col; ++i)
                        sums[i] += matrix[b][i];
                    set<int> cumSet;
                    cumSet.insert(0);
                    int curSum = 0;
                    for (auto sum : sums) {
                        curSum += sum;
                        auto iter = cumSet.lower_bound(curSum - k);
                        if (iter != cumSet.end()) ret = max(ret, curSum - *iter);
                        cumSet.insert(curSum);
                    }
                }
            }
        } else {
            for (int l = 0; l < col; ++l) {
                vector<int> sums(row, 0);
                for (int r = l; r < col; ++r) {
                    for (int i = 0; i < row; ++i)
                        sums[i] += matrix[i][r];
                    set<int> cumSet;
                    cumSet.insert(0);
                    int curSum = 0;
                    for (auto sum : sums) {
                        curSum += sum;
                        auto iter = cumSet.lower_bound(curSum - k);
                        if (iter != cumSet.end()) ret = max(ret, curSum - *iter);
                        cumSet.insert(curSum);
                    }
                }
            }
        }
        return ret;
    }
};
