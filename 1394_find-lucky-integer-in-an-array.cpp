class Solution {
public:
    int findLucky(vector<int>& arr) {
        int ret = -1;
        unordered_map<int, int> mp;
        for (auto n : arr) ++mp[n];
        for (const auto& item : mp) {
            if (item.first == item.second) ret = max(ret, item.first);
        }
        return ret;
    }
};
