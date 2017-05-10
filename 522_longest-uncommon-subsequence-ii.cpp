class Solution {
public:
    int findLUSlength(vector<string>& strs) {
        sort(strs.begin(), strs.end(), [](const string& s1, const string& s2) {
            return s1.size() > s2.size();
        });
        unordered_map<string, int> mp;
        for (auto str : strs)
            ++mp[str];
        for (auto s1 : strs) {
            if (mp[s1] != 1) continue;
            int cnt = 0;
            for (auto s2 : strs) {
                if (s1.size() > s2.size()) break;
                if (isSub(s1, s2))
                    if (++cnt > 1)
                        break;
            }
            if (cnt == 1) return s1.size();
        }
        return -1;
    }
    bool isSub(const string& s1, const string& s2) {
        int i = 0, j = 0;
        for (; i != s1.size() && j != s2.size(); ++j)
            if (s1[i] == s2[j])
                ++i;
        return i == s1.size();
    }
};
