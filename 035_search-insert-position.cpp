class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int b = 0, e = nums.size() - 1;
        while (b <= e) {
            const int mid = b + (e - b) / 2;
            if (nums[mid] >= target) e = mid - 1;
            else b = mid + 1;
        }
        return b;
    }
};
