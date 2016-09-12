class NumMatrix {
public:
    NumMatrix(vector<vector<int>> &matrix) {
        matrixSum.resize(matrix.size());
        for (int i = 0; i != matrix.size(); ++i) {
            matrixSum[i].resize(matrix[0].size() + 1, 0);
            for (int j = 0; j != matrix[0].size(); ++j)
                matrixSum[i][j + 1] = matrixSum[i][j] + matrix[i][j];
        }
    }

    int sumRegion(int row1, int col1, int row2, int col2) {
        int sum = 0;
        for (int i = row1; i <= row2; ++i)
            sum += matrixSum[i][col2 + 1] - matrixSum[i][col1];
        return sum;
    }
private:
    vector<vector<int> > matrixSum;
};


// Your NumMatrix object will be instantiated and called as such:
// NumMatrix numMatrix(matrix);
// numMatrix.sumRegion(0, 1, 2, 3);
// numMatrix.sumRegion(1, 2, 3, 4);
