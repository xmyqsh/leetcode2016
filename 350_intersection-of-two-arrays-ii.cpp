class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> mp;
        for (auto num : nums1) ++mp[num];
        vector<int> result;
        for (auto num : nums2) if (mp.count(num) && mp[num]) result.push_back(num), --mp[num];
        return result;
    }
};
