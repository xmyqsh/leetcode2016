class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        if (nums.size() < 2) return false;
        unordered_map<int, int> count;
        for (auto num : nums)
            if (++count[num] == 2) return true;
        return false;
    }
};
