class Solution {
public:
    int missingNumber(vector<int>& nums) {
        for (int i = 0; i < nums.size(); ++i) {
            while (nums[i] != i && nums[i] != nums.size())
                swap(nums[i], nums[nums[i]]);
        }
        for (int i = 0; i < nums.size(); ++i)
            if (nums[i] == nums.size()) return i;
        return nums.size();
    }
};

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int sum = nums.size() * (1 + nums.size()) / 2;
        for (auto num : nums) sum -= num;
        return sum;
    }
};
