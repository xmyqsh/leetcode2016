class Solution {
public:
    int findTheLongestSubstring(string s) {
        unordered_map<char, int> c2b;
        int b = 1;
        for (auto c : "aeiou") {
            c2b[c] = b;
            b <<= 1;
        }
        int mask = 0, ret = 0;
        unordered_map<int, vector<int>> maskDict;
        maskDict[0].push_back(-1);
        for (int i = 0; i != s.size(); ++i) {
            mask ^= c2b[s[i]];
            maskDict[mask].push_back(i);
        }
        for (const auto& item : maskDict) {
            ret = max(ret, item.second[item.second.size() - 1] - item.second[0]);
        }
        return ret;
    }
};
