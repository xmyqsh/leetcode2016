// dfs
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

// dp
class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int S) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if (sum < S) return 0;
        return dp(nums, S, sum);
    }
    int dp(const vector<int>& nums, int S, int sum) {
        vector<int> f(2*sum + 1, 0);
        f[sum] = 1;
        for (auto n : nums) {
            vector<int> f1(2*sum + 1, 0);
            for (int i = 0; i != f.size(); ++i) {
                if (i + n < f.size()) f1[i + n] += f[i];
                if (i - n >= 0) f1[i - n] += f[i];
            }
            swap(f1, f);
        }
        return f[sum + S];
    }
};
