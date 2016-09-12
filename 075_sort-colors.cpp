class Solution {
public:
    void sortColors(vector<int>& nums) {
        int b = 0, e = nums.size() - 1, cur = 0;
        while (cur <= e) {
            if (nums[cur] == 0) swap(nums[b++], nums[cur++]);
            else if (nums[cur] == 1) cur++;
            else swap(nums[cur], nums[e--]);
        }
    }
};
