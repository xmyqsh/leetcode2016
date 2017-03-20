class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        if (nums.size() < 2) return 0;
        sort(nums.begin(), nums.end());
        int ret = 0;
        for (int i = 0, j = 1; j != nums.size();) {
            if (i == j) ++j;
            else if (nums[j] - nums[i] < k) ++j;
            else if (nums[j] - nums[i] > k) ++i;
            else {
                ++ret; ++i; ++j;
                while (j != nums.size() && nums[j - 1] == nums[j]) ++j;
            }
        }
        return ret;
    }
};
