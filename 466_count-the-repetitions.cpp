class Solution {
public:
    int getMaxRepetitions(string s1, int n1, string s2, int n2) {
        unsigned int M = 0, i1 = 0, i2 = 0;
        while (i1 != s1.size() * n1) {
            if (s1[i1 % s1.size()] == s2[i2 % s2.size()])
                ++i2;
            ++i1;
            if (i2 == s2.size() * n2) {
                ++M;
                i2 = 0;
            }
        }
        return M;
    }
};
