// nlog(n)
class Solution {
public:
    int minMoves2(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int i = 0, j = nums.size() - 1, ret = 0;
        while (i < j)
            ret += nums[j--] - nums[i++];
        return ret;
    }
};
