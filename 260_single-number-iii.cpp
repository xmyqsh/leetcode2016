class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        if (nums.size() == 2) return nums;
        int nor = 0;
        for (auto num : nums) nor ^= num;
        int sig = nor - (nor & (nor - 1));
        vector<int> result(2, 0);
        for (auto num : nums)
            if (num & sig) result[0] ^= num;
            else result[1] ^= num;
        return result;
    }
};
