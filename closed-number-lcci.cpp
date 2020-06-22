class Solution {
public:
    vector<int> findClosedNumbers(int num) {
        if (num == 0) return {-1, -1};
        vector<int> bits(32, 0);
        for (unsigned int base = 1, i = 0; i != 32; ++i, base <<= 1) {
            if (num & base) bits[i] = 1;
        }
        vector<int> result(2, -1);
        unsigned int j, baseJ, tmpI = 0;
        for (j = 0, baseJ = 1; j != 32 && bits[j] == 0; ++j, baseJ <<= 1);
        result[0] = 0;
        for (; j != 32 && bits[j] == 1; ++j, baseJ <<= 1) ++tmpI;
        for (unsigned int k = 1, baseK = 1; k != tmpI; ++k, baseK <<= 1) result[0] |= baseK;
        result[0] |= baseJ;
        for (++j, baseJ <<= 1; j != 32; ++j, baseJ <<= 1) if (bits[j]) result[0] |= baseJ;

        unsigned int i = 0, base = 1, tmp = 0;
        for (; i != 32 && bits[i] == 1; ++i, base <<= 1) ++tmp;
        for (; i != 32 && bits[i] == 0; ++i, base <<= 1);
        if (i == 32) return result;
        int baseI = (base >> 1);
        result[1] = baseI;
        while (tmp--) {
            baseI >>= 1;
            result[1] |= baseI;
        }
        for (++i, base <<= 1; i != 32; ++i, base <<= 1) if (bits[i]) result[1] |= base;
        return result;
    }
};
