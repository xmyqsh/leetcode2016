class Solution {
public:
    int maxProduct(vector<int>& nums) {
        if (nums.empty()) return 0;
        int maxPro = nums[0], maxHere = nums[0], minHere = nums[0];
        for (int i = 1; i < nums.size(); ++i) {
            int maxTmp = max(max(maxHere * nums[i], minHere * nums[i]), nums[i]);
            int minTmp = min(min(maxHere * nums[i], minHere * nums[i]), nums[i]);
            maxHere = maxTmp;
            minHere = minTmp;
            maxPro = max(maxPro, maxHere);
        }
        return maxPro;
    }
};
