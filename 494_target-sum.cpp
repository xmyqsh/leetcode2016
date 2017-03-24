class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int S) {
        if (nums.empty()) return 0;
        int ret = 0;
        dfs(ret, nums, S, 0, 0);
        return ret;
    }
    void dfs(int& ret, const vector<int>& nums, int S, int cur, int idx) {
        if (idx == nums.size()) {
            if (cur == S) ++ret;
            return;
        }
        dfs(ret, nums, S, cur + nums[idx], idx + 1);
        dfs(ret, nums, S, cur - nums[idx], idx + 1);
    }
};
