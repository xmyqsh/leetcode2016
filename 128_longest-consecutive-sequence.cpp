class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if (nums.size() < 2) return nums.size();
        unordered_map<int, int> mp;
        for (int i = 0; i < nums.size(); ++i) mp[nums[i]] = 1;
        int cnt = 0, cur, ret = 0;
        for (int i = 0; i < nums.size(); ++i) {
            if (!mp[nums[i]]) continue;
            cur = nums[i];
            cnt = 1;
            for (int j = nums[i] - 1; mp.count(j) && mp[j]; --j) {
                mp[j] = 0;
                ++cnt;
            }
            for (int j = nums[i] + 1; mp.count(j) && mp[j]; ++j) {
                mp[j] = 0;
                ++cnt;
            }
            ret = max(ret, cnt);
        }
        return ret;
    }
};
