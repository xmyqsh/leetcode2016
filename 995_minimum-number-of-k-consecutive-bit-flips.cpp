class Solution {
public:
    int minKBitFlips(vector<int>& A, int K) {
        vector<int> flips(A.size() + 1, 0);
        int flip = 0, ret = 0;
        for (int i = 0; i != A.size(); ++i) {
            // running accumulate
            flip ^= flips[i];
            // XOR same as mod 2
            if (A[i] == flip) {
                if (i + K > A.size()) return -1;
                ++ret;
                flip ^= 1;
                flips[i + K] = 1;
            }
        }
        return ret;
    }
};
