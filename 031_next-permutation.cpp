// make next min larger
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        // split the sequence where second part is reverse ordered
        int x;
        for (x = n - 2; x >= 0 && nums[x] >= nums[x + 1]; --x);
        if (x < 0) {
            reverse(nums.begin(), nums.end());
            return;
        }
        // make first part min larger
        int y;
        for (y = n - 1; nums[y] <= nums[x]; --y);
        swap(nums[x], nums[y]);
        // make second part min
        reverse(nums.begin() + x + 1, nums.end());
    }
};
