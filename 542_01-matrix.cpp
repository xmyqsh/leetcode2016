// Time Limit Exceeded 
class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& matrix) {
        if (matrix.empty() || matrix[0].empty()) return vector<vector<int> >();
        int m = matrix.size(), n = matrix[0].size();
        vector<vector<int> > result(m, vector<int>(n));
        for (int i = 0; i != m; ++i) {
            for (int j = 0; j != n; ++j) {
                vector<vector<int> > visited(m, vector<int>(n, 0));
                result[i][j] = matrix[i][j] ? bfs(matrix, visited, i, j) : 0;
            }
        }
        return result;
    }
    int bfs(const vector<vector<int> >& matrix, vector<vector<int> >& visited, int x, int y) {
        int dis = 0;
        vector<vector<int> > dir = { {0, -1}, {-1, 0}, {0, 1}, {1, 0} };
        queue<pair<int, int> > q, q_next;
        q_next.push(make_pair(x, y));
        visited[x][y] = 1;
        while (!q_next.empty()) {
            swap(q, q_next);
            ++dis;
            while (!q.empty()) {
                pair<int, int> p = q.front();
                q.pop();
                for (int i = 0; i != 4; ++i) {
                    x = p.first + dir[i][0];
                    y = p.second + dir[i][1];
                    if (x < 0 || y < 0 || x == matrix.size() || y == matrix[0].size()) continue;
                    if (visited[x][y]) continue;
                    visited[x][y] = 1;
                    if (matrix[x][y]) q_next.push(make_pair(x, y));
                    else return dis;
                }
            }
        }
        return dis;
    }
};
