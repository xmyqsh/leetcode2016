class Solution {
public:
    int mySqrt(int x) {
        //return (int)(sqrt(x));
        int b = 1, e = x;
        while (b <= e) {
            const long long mid = b + (e - b) / 2;
            if (mid * mid <= x) b = mid + 1;
            else e = mid - 1;
        }
        return e;
    }
};
