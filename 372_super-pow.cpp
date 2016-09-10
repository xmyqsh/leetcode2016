class Solution {
public:
    int superPow(int a, vector<int>& b) {
        long result = normPow(a, b[0]);
        for (int i = 1; i != b.size(); ++i)
            result = (normPow(result, 10) * normPow(a, b[i])) % 1337;
        return result;
    }
    long normPow(long a, long b) {
        if (b == 0) return 1;
        if (b == 1) return a;
        long tmp = normPow(a, b / 2);
        if (b % 2) return (((tmp * tmp) % 1337) * a) % 1337;
        else return (tmp * tmp) % 1337;
    }
};
