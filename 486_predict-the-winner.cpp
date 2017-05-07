class Solution {
public:
    bool PredictTheWinner(vector<int>& nums) {
        /* 	Runtime Error
        if (nums.size() <= 2) return true; 
        vector<vector<int> > dp(nums.size(), vector<int>(nums.size(), 0));
        int sum = 0;
        for (int i = 0; i != nums.size(); ++i) {
            dp[i][i] = nums[i];
            dp[i][i + 1] = max(nums[i], nums[i + 1]);
            sum += nums[i];
        }
        for (int gap = 2; gap != nums.size(); ++gap) {
            for (int i = 0, j = gap; j != nums.size(); ++i, ++j)
                dp[i][j] = max(nums[i] + min(dp[i + 2][j], dp[i + 1][j - 1]),
                               nums[j] + min(dp[i + 1][j - 1], dp[i][j - 2]));
        }
        return dp[0][nums.size() - 1] * 2 >= sum;
        */
        if (nums.size() <= 2) return true;
        vector<vector<int> > dp(nums.size(), vector<int>(nums.size(), 0));
        //vector<vector<int> > sum(nums.size(), vector<int>(nums.size(), 0));
        vector<int> sum(nums.size(), 0);
        dp[0][0] = sum[0] = nums[0];
        for (int i = 0; i != nums.size(); ++i) {
            dp[i][i] = nums[i];
            sum[i] = sum[i - 1] + nums[i];
        }
        for (int gap = 1; gap != nums.size(); ++gap) {
            for (int i = 0, j = gap; j != nums.size(); ++i, ++j)
                dp[i][j] = sum[j] - sum[i - 1] - min(dp[i][j - 1], dp[i + 1][j]);
        }
        return dp[0][nums.size() - 1] * 2 >= sum[nums.size() - 1];
    }
};

//  version 1
//  dp[i, j] = max(nums[i] + min(dp[i + 1, j - 1], dp[i + 2, j]),
//                 nums[j] + min(dp[i, j - 2], dp[i + 1, j - 1]))
//  dp[i, i] = nums[i]
//  dp[i, i + 1] = max(nums[i], nums[i + 1])

// version 2
// dp(i, j) = max(sum(i, j) - dp(i, j-1), sum(i, j) - dp(i+1, j))
