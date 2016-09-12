class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        if (obstacleGrid.empty() || obstacleGrid[0][0] == 1) return 0;
        vector<int> f(obstacleGrid[0].size() + 1, 0);
        f[1] = 1;
        for (int i = 0; i != obstacleGrid.size(); ++i)
            for (int j = 0; j != obstacleGrid[0].size(); ++j)
                f[j + 1] = obstacleGrid[i][j] == 1 ? 0 : f[j + 1] + f[j];
        return f[obstacleGrid[0].size()];
    }
};
