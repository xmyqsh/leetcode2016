// Forward declaration of guess API.
// @param num, your guess
// @return -1 if my number is lower, 1 if my number is higher, otherwise return 0
int guess(int num);

class Solution {
public:
    int guessNumber(int n) {
        int b = 1, e = n;
        while (b < e) {
            const int mid = b + (e - b) / 2;
            int gRet = guess(mid);
            if (gRet == -1) e = mid - 1;
            else if (gRet == 1) b = mid + 1;
            else return mid;
        }
        return b;
    }
};
