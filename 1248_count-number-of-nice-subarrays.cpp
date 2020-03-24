class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        map<int, int> idx2cnt;
        vector<int> dp(nums.size() + 1, 0);
        int ret = 0;
        for (int i = 0; i != nums.size(); ++i) {
            dp[i + 1] = dp[i] + (nums[i] & 1);
            auto p = equal_range(dp.begin(), dp.begin() + i + 2, dp[i + 1] - k);
            ret += p.second - p.first;
        }
        return ret;
    }
};
