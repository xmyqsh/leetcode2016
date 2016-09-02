class Solution {
public:
    int findMin(vector<int>& nums) {
        int b = 0, e = nums.size() - 1;
        while (b < e) {
            const int mid = b + (e - b) / 2;
            if (nums[mid] < nums[e]) e = mid;
            else if (nums[mid] > nums[e]) b = mid + 1;
            else --e;
        }
        return nums[b];
    }
};
