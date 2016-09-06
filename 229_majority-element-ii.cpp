class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int first, second, cnt1 = 0, cnt2 = 0;
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] == first) ++cnt1;
            else if (nums[i] == second) ++cnt2;
            else if (cnt1 == 0) {
                first = nums[i];
                cnt1 = 1;
            } else if (cnt2 == 0) {
                second = nums[i];
                cnt2 = 1;
            } else {
                --cnt1;
                --cnt2;
            }
        }
        cnt1 = cnt2 = 0;
        vector<int> result;
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] == first) ++cnt1;
            else if (nums[i] == second) ++cnt2;
        }
        if (cnt1 * 3 > nums.size()) result.push_back(first);
        if (cnt2 * 3 > nums.size()) result.push_back(second);
        return result;
    }
};
