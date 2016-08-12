class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        int x;
        for (x = n - 2; x >= 0 && nums[x] >= nums[x + 1]; --x);
        if (x < 0) {
            reverse(nums.begin(), nums.end());
            return;
        }
        int y;
        for (y = n - 1; nums[y] <= nums[x]; --y);
        swap(nums[x], nums[y]);
        reverse(nums.begin() + x + 1, nums.end());
    }
};
