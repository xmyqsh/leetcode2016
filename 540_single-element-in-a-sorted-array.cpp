class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int b = 0, e = nums.size() / 2;
        while (b < e) {
            const int midMul2 = (b + e) / 2 * 2;
            if (nums[midMul2] != nums[midMul2 + 1]) e = midMul2 / 2;
            else b = midMul2 / 2 + 1;
        }
        return nums[2 * b];
    }
};
