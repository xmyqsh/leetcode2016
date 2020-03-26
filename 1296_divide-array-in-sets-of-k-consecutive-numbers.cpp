class Solution {
public:
    bool isPossibleDivide(vector<int>& nums, int k) {
        map<int, int> mp;
        for (auto n : nums) ++mp[n];
        while (!mp.empty()) {
            auto cur = mp.begin()->first;
            for (int i = 0; i != k; ++i, ++cur) {
                if (!mp.count(cur)) return false;
                if (--mp[cur] == 0) mp.erase(cur);
            }
        }
        return true;
    }
};
