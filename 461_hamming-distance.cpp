class Solution {
public:
    int hammingDistance(int x, int y) {
        return ones(x ^ y);
    }
    int ones(int n) {
        int cnt = 0;
        while (n) {
            ++cnt;
            n &= (n - 1);
        }
        return cnt;
    }
};
