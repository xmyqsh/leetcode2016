class Solution {
public:
    int arrayNesting(vector<int>& nums) {
        int result = 0;
        for (int i = 0; i != nums.size(); ++i) {
            int cur = i, cnt = 0;
            while (nums[cur] >= 0) {
                int val = nums[cur];
                nums[cur] = -1;
                cur = val;
                ++cnt;
            }
            result = max(result, cnt);
        }
        return result;
    }
};
