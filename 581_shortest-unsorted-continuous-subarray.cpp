class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        if (nums.size() < 2) return 0;
        vector<int> nums2(nums);
        sort(nums2.begin(), nums2.end());
        int i = 0, j = nums.size() - 1;
        while (i != nums.size() && nums2[i] == nums[i]) ++i;
        while (j >= i && nums2[j] == nums[j]) --j;
        if (j < i) return 0;
        return j - i + 1;
    }
};
