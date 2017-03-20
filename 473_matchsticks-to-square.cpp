class Solution {
public:
    bool makesquare(vector<int>& nums) {
        if (nums.size() < 4) return false;
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if (sum % 4) return false;
        sort(nums.begin(), nums.end(), [](const int &l, const int &r){return l > r;});
        return dfs(0, nums, 0, 0, 0, 0, sum / 4);
    }
    bool dfs(int cur, const vector<int>& nums, int first, int second, int third, int forth, int edge) {
        if (first > edge || second > edge || third > edge || forth > edge) return false;
        if (cur == nums.size()) return true;
        return dfs(cur + 1, nums, first + nums[cur], second, third, forth, edge)
            || dfs(cur + 1, nums, first, second + nums[cur], third, forth, edge)
            || dfs(cur + 1, nums, first, second, third + nums[cur], forth, edge)
            || dfs(cur + 1, nums, first, second, third, forth + nums[cur], edge);
    }
};
