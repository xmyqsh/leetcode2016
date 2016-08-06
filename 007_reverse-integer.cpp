class Solution {
public:
    int reverse(int x) {
        bool flag = false;
        if (x < 0) {
            flag = true;
            x = -x;
        }
        int result = 0;
        while (x) {
            int n = x % 10;
            if ((INT_MAX - n) / 10 < result) return 0;
            result = 10 * result + n;
            x /= 10;
        }
        return flag ? -result : result;
    }
};
