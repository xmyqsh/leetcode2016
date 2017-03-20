class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int ret = 0, cnt = 0;
        for (auto num : nums) {
            if (num) ++cnt;
            else {
                ret = max(ret, cnt);
                cnt = 0;
            }
        }
        return max(ret, cnt);
    }
};
