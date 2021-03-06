class Solution {
public:
    int rob(vector<int>& nums) {
        if (nums.empty()) return 0;
        vector<int> dp(nums.size(), 0);
        for (int i = 0; i < nums.size(); ++i)
            dp[i] = max(nums[i] + (i < 2 ? 0 : dp[i - 2]), (i < 1 ? 0 : dp[i - 1]));
        return dp[nums.size() - 1];
    }
};

class Solution {
public:
    int rob(vector<int>& nums) {
        int best2 = 0, best1 = 0;
        for (int i = 0; i < nums.size(); ++i) {
            const int tmp = nums[i] + best2;
            best2 = best1;
            best1 = max(best1, tmp);
        }
        return best1;
    }
};
