class Solution {
public:
    int flipLights(int n, int m) {
        unordered_set<int> state;
        n = min(n, 6);
        int mask = 0;
        for (int i = 0, k = 1; i != n; ++i, k <<= 1) mask |= k;
        for (int im = 0; im != 16; ++im) {
            int nbit = countBit(im);
            if (nbit % 2 == m % 2 && nbit <= m) {
                int light = 0;
                if (im & (1 << 0)) light ^= (0b111111 & mask);
                if (im & (1 << 1)) light ^= (0b101010 & mask);
                if (im & (1 << 2)) light ^= (0b010101 & mask);
                if (im & (1 << 3)) light ^= (0b001001 & mask);
                state.insert(light);
            }
        }
        return state.size();
    }
    int countBit(int n) {
        int cnt = 0;
        while (n) {
            ++cnt;
            n &= n - 1;
        }
        return cnt;
    }
};
/*
property 0: n's period is 6(can be further reduced to 3)
1 2 3 4 5 6 | 7 8 9 A B C
  2   4   6 |   8   A   C
1   3   5   | 7   9   B
1     4     | 7     A

According to 1 and 2, m's period is 2^4 = 16
property 1: operation order unaware
property 2: ivertable operation
1 <--> 1            ---> 2 operation
2 <--> 2            ---> 2 operation
3 <--> 3            ---> 2 operation
4 <--> 4            ---> 2 operation
1 <--> (2, 3)       ---> 3 operation  ---> has not been used yet
*/
