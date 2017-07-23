class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        unordered_map<int, int> mp;
        for (auto num : nums) ++mp[num];
        vector<int> result(2);
        for (int i = 1; i <= nums.size(); ++i) {
            if (!mp.count(i)) result[1] = i;
            else if (mp[i] == 2) result[0] = i;
        }
        return result;
    }
};
