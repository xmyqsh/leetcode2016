class Solution {
public:
    int minSteps(string s, string t) {
        unordered_map<char, int> mp;
        for (auto c : s) ++mp[c];
        for (auto c : t) --mp[c];
        int ret = 0;
        for (const auto& item : mp) ret += abs(item.second);
        return ret / 2;
    }
};
