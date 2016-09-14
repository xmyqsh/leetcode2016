class Solution {
public:
    int countDigitOne(int n) {
        long base = 1;
        int result = 0, low, cur, high;
        while (n >= base) {
            //low = n % base;
            cur = n / base % 10;
            high = n / base / 10;
            if (cur > 1) result += (high + 1) * base;
            else if (cur == 1) result += high * base + (n % base) + 1;
            else result += high * base;
            base *= 10;
        }
        return result;
    }
};
