class Solution {
public:
    vector<int> drawLine(int length, int w, int x1, int x2, int y) {
        int numPerLine = w / 32;
        x1 += w * y;
        x2 += w * y;
        int idx = 0;
        vector<int> result; result.reserve(length);
        for (; idx + w < x1; idx += w) {
            for (int k = 0; k != numPerLine; ++k)
                result.push_back(0);
        }
        assert(idx <= x1);
        assert(x2 < idx + w);
        for (; idx + 32 < x1; idx += 32) result.push_back(0);
        unsigned int i = 0, base = (1 << 31);
        for (; idx != x1; ++i, ++idx, base >>= 1);
        unsigned int cur = 0;
        for (; i != 32 && idx <= x2; ++i, ++idx, base >>= 1) cur |= base;
        result.push_back(cur);
        for (; idx + 32 <= x2; idx += 32) result.push_back(-1);
        if (idx <= x2) {
            for (cur = 0, i = 0, base = (1 << 31); idx <= x2; ++i, ++idx, base >>= 1) cur |= base;
            result.push_back(cur);
        }
        for (; idx + 32 <= length * 32; idx += 32) result.push_back(0);
        return result;
    }
};
