class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> mp;
        vector<int> result(2);
        for (size_t i = 0; i < nums.size(); ++i)
            mp[nums[i]] = i;
        for (size_t i = 0; i < nums.size(); ++i) {
            if (mp.count(target - nums[i]) && i != mp[target - nums[i]]) {
                result[0] = i;
                result[1] = mp[target - nums[i]];
                break;
            }
        }
        return result;
    }
};
