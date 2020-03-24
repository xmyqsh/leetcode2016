class Solution {
public:
    int minimumSwap(string s1, string s2) {
        if (s1.size() != s2.size()) return -1;
        int xy = 0, yx = 0;
        for (int i = 0; i != s1.size(); ++i) {
            if (s1[i] == s2[i]) continue;
            if (s1[i] == 'x') ++xy;
            else ++yx;
        }
        if (((xy + yx) & 1) == 1) return -1;
        return ((min(xy, yx) + 1) / 2 * 2) + (max(xy, yx) - min(xy, yx)) / 2;
    }
};
