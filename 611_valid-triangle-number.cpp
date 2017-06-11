class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        if (nums.size() < 3) return 0;
        sort(nums.begin(), nums.end());
        int result = 0;
        for (int i = 0; i != nums.size() - 2; ++i) {
            for (int j = i + 1; j != nums.size() - 1; ++j) {
                int k = binary_search(nums, j + 1, nums.size() - 1, nums[i] + nums[j]);
                result += k - j;
            }
        }
        return result;
    }
    int binary_search(const vector<int>& nums, int b, int e, int twoSum) {
        while (b <= e) {
            const int mid = (b + e) / 2;
            if (twoSum > nums[mid]) b = mid + 1;
            else e = mid - 1;
        }
        return e;
    }
};
