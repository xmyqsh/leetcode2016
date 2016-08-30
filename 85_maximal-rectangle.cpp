class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        if (matrix.empty() || matrix[0].empty()) return 0;
        vector<int> height(matrix[0].size() + 1, 0);
        int maxArea = 0;
        for (int i = 0; i < matrix.size(); ++i) {
            int curLeft = 0, curRight = matrix[0].size();
            for (int j = 0; j < matrix[0].size(); ++j) {
                if (matrix[i][j] == '1') ++height[j];
                else height[j] = 0;
            }
            stack<int> sk;
            for (int j = 0; j < height.size();) {
                if (sk.empty() || height[j] > height[sk.top()]) {
                    sk.push(j++);
                } else {
                    const int idx = sk.top();
                    sk.pop();
                    maxArea = max(maxArea, height[idx] * (sk.empty() ? j : j - sk.top() - 1));
                }
            }
        }
        return maxArea;
    }
};
