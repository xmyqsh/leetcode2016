class Solution {
public:
    vector<int> pancakeSort(vector<int>& A) {
        vector<int> result;
        for (int i = 1; i != A.size() + 1; ++i) {
            int j = 0;
            while (A[j] != i) ++j;
            if (j != A.size() - i) {
                reverse(A.begin(), A.begin() + j + 1);
                result.push_back(j + 1);
                reverse(A.begin(), A.begin() + A.size() - i + 1);
                result.push_back(A.size() - i + 1);
            }
        }
        result.push_back(A.size());
        return result;
    }
};
/*
[3,2,4,1]
[2,3,4,1]
[4,3,2,1]
[1,2,3,4]
*/
