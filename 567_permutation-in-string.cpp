class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if (s2.size() < s1.size()) return false;
        vector<int> m1(26, 0), m2(26, 0);
        int i = 0;
        for (; i != s1.size(); ++i) {
            ++m1[s1[i] - 'a'];
            ++m2[s2[i] - 'a'];
        }
        if (m1 == m2) return true;
        for (; i != s2.size(); ++i) {
            ++m2[s2[i] - 'a'];
            --m2[s2[i - s1.size()] - 'a'];
            if (m1 == m2) return true;
        }
        return false;
    }
};
