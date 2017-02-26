class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        if (nums.size() < 2) return 0;
        int sum = 0, ret = 0;
        unordered_map<int, int> mp;
        mp[0] = -1;
        for (int i = 0; i != nums.size(); ++i) {
            sum += nums[i] == 0 ? -1 : 1;
            if (mp.find(sum) == mp.end()) mp[sum] = i;
            else ret = max(ret, i - mp[sum]);
        }
        return ret;
    }
};
