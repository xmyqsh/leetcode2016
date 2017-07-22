class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        vector<double> sums(nums.size() + 1, 0.);
        double result = -1e4;
        for (int i = 0; i != nums.size(); ++i)
            sums[i + 1] = sums[i] + nums[i];
        for (int i = 0; i + k != sums.size(); ++i) {
            for (int j = k; i + j != sums.size(); ++j) {
                double sum = sums[i + j] - sums[i];
                if (j * result < sum)
                    result = sum / j;
            }
        }
        return result;
    }
};
