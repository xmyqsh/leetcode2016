class Solution {
public:
    int repeatedNTimes(vector<int>& A) {
        for (int i = 0; i + 2 != A.size(); i += 2) {
            if (A[i] == A[i + 1]) return A[i];
            if (A[i] == A[i + 2]) return A[i];
            if (A[i + 1] == A[i + 3]) return A[i + 1];
        }
        if (A[1] == A[2]) return A[1];
        if (A[0] == A[3]) return A[0];
        return A.back();
    }
};
/*
1 2 3 4 5 6 7 7 7 7 7 7

1 7 7 2 3 7 7 4 5 7 7 6
7 1 2 7 7 3 4 7 7 5 6 7
*/
