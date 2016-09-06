class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.size() != t.size()) return false;
        if (s.empty()) return true;
        if (s.size() == 1) return s[0] == t[0];
        vector<int> count(256, 0);
        for (int i = 0; i < s.size(); ++i)
            ++count[s[i]], --count[t[i]];
        for (int i = 'a'; i <= 'z'; ++i)
            if (count[i]) return false;
        return true;
    }
};
