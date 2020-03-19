// O(N^2)
// TODO:  Time Limit Exceeded
class Solution {
public:
    int maxValueAfterReverse(vector<int>& nums) {
        int value = 0, n = nums.size();
        for (int i = 0; i != n - 1; ++i) {
            value += abs(nums[i] - nums[i + 1]);
        }
        int ret = value;
        for (int i = 1; i != n - 1; ++i) {
            ret = max(ret, value - abs(nums[i + 1] - nums[i]) + abs(nums[i + 1] - nums[0]));
            ret = max(ret, value - abs(nums[i - 1] - nums[i]) + abs(nums[i - 1] - nums[n - 1]));
        }
        for (int i = 1; i != n - 1; ++i) {
            for (int j = i + 1; j != n - 1; ++j) {
                ret = max(ret, value - abs(nums[i - 1] - nums[i]) - abs(nums[j + 1] - nums[j])
                                     + abs(nums[i - 1] - nums[j]) + abs(nums[j + 1] - nums[i]));
            }
        }
        return ret;
    }
};
