class Solution {
public:
    bool hasValidPath(vector<vector<int>>& grid) {
        unordered_map<int, unordered_map<char, char>> mp;
        mp[1]['L'] = 'R'; mp[1]['R'] = 'L';
        mp[2]['U'] = 'D'; mp[2]['D'] = 'U';
        mp[3]['L'] = 'D'; mp[3]['D'] = 'L';
        mp[4]['R'] = 'D'; mp[4]['D'] = 'R';
        mp[5]['L'] = 'U'; mp[5]['U'] = 'L';
        mp[6]['R'] = 'U'; mp[6]['U'] = 'R';
        int c = grid[0][0];
        //if (grid[0][0] == 4 || grid[0][0] == 5) return false;
        char cur = (grid[0][0] == 1 || grid[0][0] == 3) ? 'L' : 'U';
        int m = grid.size(), n = grid[0].size();
        //if (grid[m - 1][n - 1] == 4 || grid[m - 1][n - 1] == 5) return false;
        for (char cur : {'L', 'R', 'U', 'D'}) {
        vector<vector<int>> visited(m, vector<int>(n, 0));
        int i = 0, j = 0;
        while (visited[i][j] == 0) {
            visited[i][j] = 1;

            int c = grid[i][j];
            if (!mp[c].count(cur)) break; //return false;
            
            if (i == m - 1 && j == n - 1) return true;
            
            auto nxt = mp[c][cur];
            if (nxt == 'L') {
                --j;
                cur = 'R';
            } else if (nxt == 'R') {
                ++j;
                cur = 'L';
            } else if (nxt == 'U') {
                --i;
                cur = 'D';
            } else { // nxt == 'D'
                ++i;
                cur = 'U';
            }
            if (i == -1 || j == -1 || i == m || j == n) break; //return false;
            if (visited[i][j]) break; //return false;
        }
        }
        return false;
    }
};
