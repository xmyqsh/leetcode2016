class Solution {
public:
    bool canJump(vector<int>& nums) {
        if (nums.size() < 2) return true;
        int gap = 1;
        for (int i = nums.size() - 2; i >= 1; --i) {
            if (nums[i] >= gap) gap = 1;
            else ++gap;
        }
        return nums[0] >= gap;
    }
};
