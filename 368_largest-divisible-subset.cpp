class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        if (nums.size() < 2) return nums;
        sort(nums.begin(), nums.end());
        vector<pair<int, int> > dp(nums.size(), make_pair(1, -1));
        int maxIdx = 0;
        for (int i = 1; i != nums.size(); ++i) {
            for (int j = i - 1; j >= 0; --j)
                if ((!(nums[j] % nums[i]) || !(nums[i] % nums[j])) && dp[i].first < dp[j].first + 1)
                    dp[i] = make_pair(dp[j].first + 1, j);
            if (dp[maxIdx].first < dp[i].first)
                maxIdx = i;
        }
        vector<int> result; result.reserve(nums.size());
        do {
            result.push_back(nums[maxIdx]);
            maxIdx = dp[maxIdx].second;
        } while (maxIdx != -1);
        return result;
    }
};
