class Solution {
public:
    int getSum(int a, int b) {
        if (a < b) swap(a, b);
        int result = 0;
        for (int i = 1; i != 0; i <<= 1) {
            int ai = (a & i), bi = (b & i), carry = (result & i);
            if (ai & bi & carry) {
                result |= i;
                result |= (i << 1);
            } else if ((ai & bi) || (ai & carry) || (bi & carry)) {
                result &= ~(i);
                result |= (i << 1);
            } else if (ai || bi) result |= i;
        }
        return result;
    }
};
