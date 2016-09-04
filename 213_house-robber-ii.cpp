class Solution {
public:
    int rob(vector<int>& nums) {
        if (nums.empty()) return 0;
        if (nums.size() == 1) return nums[0];
        return max(rob(nums, 0, (int)nums.size() - 1), rob(nums, 1, (int)nums.size()));
    }
    int rob(vector<int>& nums, int begin, int end) {
        int best2 = 0, best1 = 0;
        for (int i = begin; i < end; ++i) {
            const int tmp = best2 + nums[i];
            best2 = best1;
            best1 = max(best1, tmp);
        }
        return best1;
    }
};
