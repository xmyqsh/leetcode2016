class Solution {
public:
    int lastRemaining(int n) {
        int start = 1, remain = n, step = 1;
        bool left = true;
        while (remain != 1) {
            if (left || (remain & 1)) start += step;
            remain /= 2;
            step *= 2;
            left = !left;
        }
        return start;
    }
};

// recur
class Solution {
public:
    int lastRemaining(int n) {
        return n == 1 ? 1 : 2 * (1 + n / 2 - lastRemaining(n / 2));
    }
};
