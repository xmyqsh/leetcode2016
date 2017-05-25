class Solution {
public:
    int findLHS(vector<int>& nums) {
        if (nums.size() < 2) return 0;
        int result = 0;
        unordered_map<int, int> mp;
        for (auto num : nums) {
            ++mp[num];
            if (mp.count(num - 1)) result = max(result, mp[num] + mp[num - 1]);
            if (mp.count(num + 1)) result = max(result, mp[num] + mp[num + 1]);
        }
        return result;
    }
};
