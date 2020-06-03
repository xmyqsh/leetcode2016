// For case: N = 21, K = 17, W = 10
class Solution {
public:
    double new21Game(int N, int K, int W) {
        return 0.1 * get_n(7) + 0.2 * get_n(8) + 0.3 * get_n(9) + 0.4 * get_n(10) +
                0.5 * (get_n(11) + get_n(12) + get_n(13) + get_n(14) + get_n(15) + get_n(16));
    }
    double get_n(int n) {
        if (n == 0) return 1;
        double ret = 0;
        for (int i = 1; i != 11; ++i) {
            if (i <= n) ret += 0.1 * get_n(n - i);
        }
        return ret;
    }
};

/*
16 + 5 = 21    16 + 1 = 17      ---> 5
15 + 6 = 21    15 + 2 = 17      ---> 5
14 + 7 = 21    14 + 3 = 17      ---> 5
13 + 8 = 21    13 + 4 = 17      ---> 5
12 + 9 = 21    12 + 5 = 17      ---> 5
11 +10 = 21    11 + 6 = 17      ---> 5
10 +10 = 20    10 + 7 = 17      ---> 4
 9 +10 = 19     9 + 8 = 17      ---> 3
 8 +10 = 18     8 + 9 = 17      ---> 2
 7 +10 = 17     7 +10 = 17      ---> 1
 --------------------------------------
                                    40
*/
