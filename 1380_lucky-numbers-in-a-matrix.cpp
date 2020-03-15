class Solution {
public:
    vector<int> luckyNumbers (vector<vector<int>>& matrix) {
        unordered_set<int> st;
        for (int i = 0; i != matrix.size(); ++i) {
            int row = matrix[i][0];
            for (int j = 1; j != matrix[0].size(); ++j) {
                row = min(row, matrix[i][j]);
            }
            st.insert(row);
        }
        vector<int> result;
        for (int j = 0; j != matrix[0].size(); ++j) {
            int col = matrix[0][j];
            for (int i = 1; i != matrix.size(); ++i) {
                col = max(col, matrix[i][j]);
            }
            if (st.count(col)) result.push_back(col);
        }
        return result;
    }
};
