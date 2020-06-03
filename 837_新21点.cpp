// Time limit exceed:
// exceeded Case: N = 9632, K = 6575, W = 5602
// 卡这么紧干嘛？！！
class Solution {
public:
    double new21Game(int N, int K, int W) {
        if (K == 0) return 1;
        vector<double> cache(N + 1, 0); cache[0] = 1;
        _W = (double)1 / W;
        w = W;
        double ret = 0;
        if (min(N, K) <= W) {
            for (int i = 1; i < K; ++i) {
                ret += _W * (min(N - i, W) - (K - i) + 1) * get_n(i, cache);
            }
            for (int i = K; i <= min(N, W); ++i) ret += _W;
            return ret;
        }
        for (int i = K - W, j = 1; i < N - W; ++i, ++j) {
            ret += _W * j * get_n(i, cache);
        }
        for (int i = N - W; i < K; ++i) {
            ret += _W * (N - K + 1) * get_n(i, cache);
        }
        return ret;
    }
    double get_n(int n, vector<double>& cache) {
        if (cache[n]) return cache[n];
        double ret = 0;
        for (int i = 1; i != min(n + 1, w + 1); ++i) {
            ret += _W * get_n(n - i, cache);
        }
        cache[n] = ret;
        return ret;
    }
private:
    double _W;
    int w;
};

/*
For case: N = 10, K = 7, W = 8
6 + 4 = 10      6 + 1 = 7              4     min(N - i, W) - (K - i) + 1
5 + 5 = 10      5 + 2 = 7
4 + 6 = 10      4 + 3 = 7
3 + 7 = 10      3 + 4 = 7
2 + 8 = 10      2 + 5 = 7              4
1 + 8 = 9       1 + 6 = 7              3
7
8
9
*/

/*
For case: N = 9, K = 3, W = 6
2 + 6 = 8       2 + 1 = 3         ----> 6         W - (K - i) + 1
1 + 6 = 7       1 + 2 = 3         ----> 5
3
4
5
6
*/

/*
For case: N = 6, K = 3, W = 10
2 + 4 = 6      2 + 1 = 3        ---> 4       2 = K - 1          4 = N - K + 1
1 + 5 = 6      1 + 2 = 3        ---> 4       1 = 1
3                               ---> 1       3 = K
4                               ---> 1
5                               ---> 1
6                               ---> 1       6 = N
*/

/*
For case: N = 21, K = 17, W = 10

16 + 5 = 21    16 + 1 = 17      ---> 5        16 = K - 1         5 = N - K + 1
15 + 6 = 21    15 + 2 = 17      ---> 5
14 + 7 = 21    14 + 3 = 17      ---> 5
13 + 8 = 21    13 + 4 = 17      ---> 5
12 + 9 = 21    12 + 5 = 17      ---> 5
11 +10 = 21    11 + 6 = 17      ---> 5        11 = N - W
10 +10 = 20    10 + 7 = 17      ---> 4        10 = N - (W + 1)
 9 +10 = 19     9 + 8 = 17      ---> 3
 8 +10 = 18     8 + 9 = 17      ---> 2
 7 +10 = 17     7 +10 = 17      ---> 1         7 = K - W
 --------------------------------------
                                    40  
*/

/*
For case: N = 21, K = 17, W = 11
16 + 5 = 21    16 + 1 = 17      ---> 5        16 = K - 1         5 = N - K + 1
15 + 6 = 21    15 + 2 = 17      ---> 5
14 + 7 = 21    14 + 3 = 17      ---> 5
13 + 8 = 21    13 + 4 = 17      ---> 5
12 + 9 = 21    12 + 5 = 17      ---> 5
11 +10 = 21    11 + 6 = 17      ---> 5
10 +11 = 21    10 + 7 = 17      ---> 5        10 = N - W          ---------->
 9 +11 = 20     9 + 8 = 17      ---> 4        9 = N - (W + 1)
 8 +11 = 19     8 + 9 = 17      ---> 3
 7 +11 = 18     7 +10 = 17      ---> 2
 6 +11 = 17     6 +11 = 17      ---> 1        6 = K - W

 9 +11 = 20     
*/
