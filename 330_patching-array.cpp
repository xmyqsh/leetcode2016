class Solution {
public:
    int minPatches(vector<int>& nums, int n) {
        sort(nums.begin(), nums.end());
        long sum = 0, end = 1;
        int idx = 0, patch = 0;
        while (end <= n) {
            if (idx < nums.size() && nums[idx] <= end) {
                sum += nums[idx++];
            } else {
                sum += end;
                ++patch;
            }
            end = sum + 1;
        }
        return patch;
    }
};
