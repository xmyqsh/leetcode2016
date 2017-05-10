class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        unordered_map<char, int> ms, mp;
        vector<int> result;
        if (s.size() < p.size()) return result;
        for (auto c : p) ++mp[c];
        int len = p.size();
        int b = 0, e = 0;
        while (e != len)
            ++ms[s[e++]];
        if (eql(ms, mp))
            result.push_back(b);
        while (e != s.size()) {
            --ms[s[b++]];
            ++ms[s[e++]];
            if (eql(ms, mp))
                result.push_back(b);
        }
        return result;
    }
    bool eql(unordered_map<char, int>& ms, unordered_map<char, int>& mp) {
        for (auto& elem : mp)
            if (!ms.count(elem.first) || ms[elem.first] != elem.second)
                return false;
        return true;
    }
};
