class Solution {
public:
    bool validMountainArray(vector<int>& A) {
        if (A.size() < 3) return false;
        if (A[0] >= A[1]) return false;
        int i;
        for (i = 2; i != A.size() && A[i - 1] < A[i]; ++i);
        if (i == A.size()) return false;
        for (; i != A.size() && A[i - 1] > A[i]; ++i);
        return i == A.size();
    }
};
