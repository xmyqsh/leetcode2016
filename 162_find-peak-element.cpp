class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int b = 0, e = nums.size() - 1;
        while (b < e) {
            const int mid = b + (e - b) / 2;
            if (mid > 0 && nums[mid] < nums[mid - 1])
                e = mid - 1;
            else if (mid < nums.size() - 1 && nums[mid] < nums[mid + 1])
                b = mid + 1;
            else
                return mid;
        }
        return b;
    }
};
