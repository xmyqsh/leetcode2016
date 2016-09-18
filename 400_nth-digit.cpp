class Solution {
public:
    int findNthDigit(int n) {
        int idx = my_upper_bound(n);
        int number = num[idx] + (n - counter[idx] + idx) / (idx + 1);
        int bit = idx - ((n - counter[idx] - 1) % (idx + 1));
        if (n == counter[idx]) bit = 0;
        return count(number, bit);
    }
    int count(int number, int bit) {
        while (bit) {
            --bit;
            number /= 10;
        }
        return number % 10;
    }
    int my_upper_bound(long n) {
        int b = 0, e = 9;
        while (b <= e) {
            const int mid = b + (e - b) / 2;
            if (counter[mid] <= n) b = mid + 1;
            else e = mid - 1;
        }
        return e;
    }
private:
    static const long counter[];
    static const int num[];
};
const long Solution::counter[] = {0, 9, 189, 2889, 38889, 488889, 5888889, 68888889, 788888889, 8888888889};
const int Solution::num[] = {0, 9, 99, 999, 9999, 99999, 999999, 9999999, 99999999, 999999999};
