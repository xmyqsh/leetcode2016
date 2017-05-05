class Solution {
public:
    int checkRecord(int n) {
        if (n == 1) return 3;
        if (n == 2) return 8;
        int M = 1e9 + 7;
        vector<int> P(n), A(n), L(n), noAP(n), noAL(n);
        P[0] = 1; A[0] = 1; L[0] = 1; noAP[0] = 1; noAL[0] = 1;
        P[1] = 3; A[1] = 2; L[1] = 3; noAP[1] = 2; noAL[1] = 2;
        for (int i = 2; i < n; ++i) {
            P[i] = ((P[i - 1] + A[i - 1]) % M + L[i - 1]) % M;
            A[i] = (noAP[i - 1] + noAL[i - 1]) % M;
            L[i] = (((P[i - 1] + A[i - 1]) % M + P[i - 2]) % M + A[i - 2]) % M;
            noAP[i] = (noAP[i - 1] + noAL[i - 1]) % M;
            noAL[i] = (noAP[i - 1] + noAP[i - 2]) % M;
        }
        return ((P[n - 1] + A[n - 1]) % M + L[n - 1]) % M;
    }
};
