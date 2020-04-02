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

// implement official lower_bound and upper_bound
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        return {lower_bound(nums, target), upper_bound(nums, target)};
    }
    int lower_bound(const vector<int>& nums, int target) {
        int b = 0, e = nums.size();
        while (b != e) {
            const int mid = b + (e - b) / 2;
            if (nums[mid] < target) b = mid + 1;
            else e = mid;
        }
        return b != nums.size() && nums[b] == target ? b : -1;
    }
    int upper_bound(const vector<int>& nums, int target) {
        int b = -1, e = nums.size() - 1;
        while (b != e) {
            const int mid = b + (e - b + 1) / 2;
            if (nums[mid] > target) e = mid - 1;
            else b = mid;
        }
        return e != -1 && nums[e] == target ? e : -1;
    }
};
