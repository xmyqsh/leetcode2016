class Solution {
public:
    int findComplement(int num) {
        int cnt = 0, num1 = num;
        while (num1) {
            ++cnt;
            num1 >>= 1;
        }
        num1 = 1;
        while (cnt--)
            num1 <<= 1;
        return ((num1 - 1) & (~num));
    }
};
