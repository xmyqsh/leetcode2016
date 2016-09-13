class Solution {
public:
    int maxCoins(vector<int>& nums) {
        if (nums.empty()) return 0;
        nums.insert(nums.begin(), 1); nums.push_back(1);
        vector<vector<int> > dp(nums.size(), vector<int>(nums.size(), 0));
        for (int k = 2; k < nums.size(); ++k)
            for (int i = 0, j = i + k; j < nums.size(); ++i, ++j)
                for (int t = i + 1; t < j; ++t)
                    dp[i][j] = max(dp[i][j], dp[i][t] + nums[i] * nums[t] * nums[j] + dp[t][j]);
        return dp[0][nums.size() - 1];
    }
};
