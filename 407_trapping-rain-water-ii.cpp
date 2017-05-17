class Solution {
public:

class mycomparison
{
public:
  bool operator() (const tuple<int, int, int>& tp1, const tuple<int, int, int>& tp2) const
  {
    return get<2>(tp1) > get<2>(tp2);
  }
};
    int trapRainWater(vector<vector<int>>& heightMap) {
        if (heightMap.empty() || heightMap[0].empty()) return 0;
        priority_queue<tuple<int, int, int>, vector<tuple<int, int, int> >, mycomparison> pq;
        int m = heightMap.size(), n = heightMap[0].size();
        vector<vector<int> > visited(m, vector<int>(n, 0));
        for (int i = 0; i != m; ++i) {
            pq.push(make_tuple(i, 0, heightMap[i][0]));
            pq.push(make_tuple(i, n - 1, heightMap[i][n - 1]));
            visited[i][0] = 1; visited[i][n - 1] = 1;
        }
        for (int j = 0; j != n; ++j) {
            pq.push(make_tuple(0, j, heightMap[0][j]));
            pq.push(make_tuple(m - 1, j, heightMap[m - 1][j]));
            visited[0][j] = 1; visited[m - 1][j] = 1;
        }
        vector<vector<int> > dir = { {0, -1}, {-1, 0}, {0, 1}, {1, 0} };
        int result = 0;
        while (!pq.empty()) {
            auto tp = pq.top(); pq.pop();
            int x = get<0>(tp), y = get<1>(tp), h = get<2>(tp);
            for (int i = 0; i != 4; ++i) {
                int nx = x + dir[i][0];
                int ny = y + dir[i][1];
                if (nx == -1 || ny == -1 || nx == m || ny == n) continue;
                if (visited[nx][ny]) continue;
                visited[nx][ny] = 1;
                result += max(0, h - heightMap[nx][ny]);
                pq.push(make_tuple(nx, ny, max(h, heightMap[nx][ny])));
            }
        }
        return result;
    }
};
