class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        if (nums.empty()) return 0;
        vector<vector<int> > dp(nums.size(), vector<int>(2, 1));
        for (int i = 1, idx; i != nums.size(); ++i) {
            for (idx = i - 1; idx >= 0 && nums[i] >= nums[idx]; --idx);
            dp[i][0] = max(dp[i - 1][0], idx < 0 ? 1 : dp[idx][1] + 1);
            for (idx = i - 1; idx >= 0 && nums[i] <= nums[idx]; --idx);
            dp[i][1] = max(dp[i - 1][1], idx < 0 ? 1 : dp[idx][0] + 1);
        }
        return max(dp[nums.size() - 1][0], dp[nums.size() - 1][1]);
    }
};
