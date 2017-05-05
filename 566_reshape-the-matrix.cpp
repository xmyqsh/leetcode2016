class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& nums, int r, int c) {
        if (nums.empty()) return nums;
        int m = nums.size(), n = nums[0].size();
        if (m * n != r * c) return nums;
        vector<vector<int> > result(r, vector<int>(c));
        for (int i = 0; i != m; ++i) {
            for (int j = 0; j != n; ++j) {
                int cnt = i * n + j;
                result[cnt / c][cnt % c] = nums[i][j];
            }
        }
        return result;
    }
};
