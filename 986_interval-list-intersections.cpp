class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& A, vector<vector<int>>& B) {
        vector<vector<int>> result;
        for (int i = 0, j = 0; i != A.size() && j != B.size(); ) {
            if (A[i][1] < B[j][1]) {
                if (B[j][0] <= A[i][1]) result.push_back({max(A[i][0], B[j][0]), A[i][1]});
                ++i;
            } else if (A[i][1] > B[j][1]) {
                if (A[i][0] <= B[j][1]) result.push_back({max(A[i][0], B[j][0]), B[j][1]});
                ++j;
            } else { // ==
                result.push_back({max(A[i][0], B[j++][0]), A[i++][1]});
                //++i; ++j;
            }
        }
        return result;
    }
};
