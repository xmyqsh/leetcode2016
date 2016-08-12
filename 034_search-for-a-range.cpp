class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> result(2);
        result[0] = searchRange(nums, target, true);
        if (result[0] == -1) result[1] = -1;
        else result[1] = searchRange(nums, target, false);
        return result;
    }
    int searchRange(const vector<int>& nums, int target, bool smallest) {
        int b = 0, e = nums.size() - 1;
        while (b <= e) {
            const int mid = b + (e - b) / 2;
            if (smallest) {
                if (nums[mid] >= target) e = mid - 1;
                else b = mid + 1;
            } else {
                if (nums[mid] <= target) b = mid + 1;
                else e = mid - 1;
            }
        }
        if (smallest) return nums[b] == target ? e + 1 : -1;
        else return nums[e] == target ? b - 1 : -1;
    }
};
