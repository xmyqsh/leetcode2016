class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.size() < 3) return nums.size();
        int idx = 1;
        for (int i = 2; i < nums.size(); ++i)
            if (nums[idx - 1] != nums[i])
                nums[++idx] = nums[i];
        return ++idx;
    }
};
