class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> result(nums.size(), 1);
        for (int i = 1; i < nums.size(); ++i)
            result[i] = result[i - 1] * nums[i - 1];
        int mul = 1;
        for (int i = nums.size() - 1; i >= 0; --i) {
            result[i] *= mul;
            mul *= nums[i];
        }
        return result;
    }
};
