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

class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> result;
        if (p.size() > s.size()) return result;
        vector<int> mp(26, 0), ms(26, 0);
        int i = 0;
        for (; i != p.size(); ++i) {
            ++mp[p[i] - 'a'];
            ++ms[s[i] - 'a'];
        }
        if (mp == ms) result.push_back(0);
        for (; i != s.size(); ++i) {
            --ms[s[i - p.size()] - 'a'];
            ++ms[s[i] - 'a'];
            if (mp == ms) result.push_back(i - p.size() + 1);
        }
        return result;
    }
};
