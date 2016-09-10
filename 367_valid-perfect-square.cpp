class Solution {
public:
    bool isPerfectSquare(int num) {
        if (num < 2) return true;
        int b = 2, e = num / 2;
        while (b <= e) {
            const long mid = b + (e - b) / 2;
            if (mid * mid < num) b = mid + 1;
            else if (mid * mid > num) e = mid - 1;
            else return true;
        }
        return false;
    }
};
