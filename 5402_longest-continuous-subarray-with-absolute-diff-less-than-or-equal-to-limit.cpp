class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        map<int, int> mp;
        int ret = 0;
        for (int b = 0, e = 0; e != nums.size(); ++e) {
            while (!mp.empty() && mp.begin()->first < nums[e] - limit) {
                if (--mp[nums[b]] == 0) mp.erase(nums[b]);
                ++b;
            }
            while (!mp.empty() && prev(mp.end())->first > nums[e] + limit) {
                if (--mp[nums[b]] == 0) mp.erase(nums[b]);
                ++b;
            }
            ret = max(ret, e - b + 1);
            ++mp[nums[e]];
        }
        return ret;
    }
};
