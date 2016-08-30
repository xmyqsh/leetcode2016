class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int b = 0, e = nums.size();
        while (b < e) {
            const int mid = b + (e - b) / 2;
            if (nums[mid] == target) return true;
            if (nums[b] < nums[mid]) {
                if (nums[b] <= target && target < nums[mid]) e = mid;
                else b = mid + 1;
            } else if (nums[b] > nums[mid]) {
                if (nums[mid] < target && target <= nums[e - 1]) b = mid + 1;
                else e = mid;
            } else {
                ++b;
            }
        }
        return false;
    }
};
