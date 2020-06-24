class Solution {
public:
    int countTriplets(vector<int>& A) {
        unordered_map<int, int> one, two;
        int sumOne = 0, sumTwo = 0, sumSelf = 0;
        for (int i = 0; i != A.size(); ++i) {
            for (const auto& item : two) {
                if ((item.first & A[i]) == 0) sumTwo += item.second;
            }
            for (int j = i - 1; j != -1; --j) ++two[A[j] & A[i]];
            for (const auto& item : one) {
                if ((item.first & A[i]) == 0) sumOne += item.second;
            }
            ++one[A[i]];
            if (A[i] == 0) sumSelf += 1;
        }
        return sumSelf + sumOne * 6 + sumTwo * 6;
    }
};
