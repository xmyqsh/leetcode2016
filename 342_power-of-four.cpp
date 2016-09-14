class Solution {
public:
    bool isPowerOfFour(int num) {
        if (num == 0) return false;
        if (num == 1) return true;
        while (num != 4) {
            if (num % 4) return false;
            num /= 4;
        }
        return true;
    }
};
