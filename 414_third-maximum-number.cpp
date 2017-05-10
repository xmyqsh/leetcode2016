class Solution {
public:
    int thirdMax(vector<int>& nums) {
        if (nums.size() == 1) return 0;
        int i = 1, first = nums[0], second, third;
        for (; i != nums.size() && nums[i] == first; ++i);
        if (i == nums.size()) return first;
        second = nums[i++];
        if (first < second) swap(first, second);
        for (; i != nums.size() && (nums[i] == first || nums[i] == second); ++i);
        if (i == nums.size()) return first;
        third = nums[i++];
        if (third > first) {
            swap(first, third);
            swap(second, third);
        } else if (third > second) {
            swap(second, third);
        }
        for (; i != nums.size(); ++i) {
            if (nums[i] == first || nums[i] == second || nums[i] == third) continue;
            if (nums[i] > third) {
                third = nums[i];
                if (third > second) {
                    swap(third, second);
                    if (second > first)
                        swap(second, first);
                }
            }
        }
        return third;
    }
};
