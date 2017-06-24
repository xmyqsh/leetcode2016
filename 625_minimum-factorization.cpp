class Solution {
public:
    int smallestFactorization(int a) {
        if (abs(a) < 10) return a;
        int sign = a >= 0 ? 1 : -1;
        a = abs(a);
        int cnt = 0;
        stringstream ss;
        for (int m = 9; m != 1; --m) {
            while (!(a % m)) {
                a /= m;
                ss << m;
                if (++cnt == 10) break;
                if (a == 1) break;
            }
        }
        if (a != 1) return 0;
        string strNum = ss.str();
        reverse(strNum.begin(), strNum.end());
        long long ret = sign * stol(strNum);
        if (ret < INT_MIN || ret > INT_MAX) return 0;
        return ret;
    }
};
