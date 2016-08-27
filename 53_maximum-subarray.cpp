class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        if (nums.empty()) return 0;
        int maxHere = nums[0], endHere = nums[0];
        for (int i = 1; i < nums.size(); ++i) {
            endHere = endHere < 0 ? nums[i] : endHere + nums[i];
            maxHere = maxHere < endHere ? endHere : maxHere;
        }
        return maxHere;
    }
};
