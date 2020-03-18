// TODO:
// back trace from top to down, from left to right cannot travel all the possible solution
class Solution {
public:
    int maxStudents(vector<vector<char>>& seats) {
        int ret = 0;
        maxStudents(seats, ret, 0, -1, seats[0].size() - 1);
        return ret;
    }
    void maxStudents(vector<vector<char>>& seats, int& ret, int cur, int x, int y) {
        int m = seats.size(), n = seats[0].size();
        if (++y == n) {
            ++x;
            y = 0;
        }
        if (x == m) {
            ret = max(ret, cur);
            return;
        }
        for (int i = x; i != m; ++i) {
            for (int j = y; j != n; ++j) {
                if (seats[i][j] == '.') {
                    seats[i][j] == 'O';
                    if (j != 0) {
                        if (seats[i][j - 1] == '.') seats[i][j - 1] = i * 10 + j;
                        if (i != 0 && seats[i - 1][j - 1] == '.') seats[i - 1][j - 1] = i * 10 + j;
                    }
                    if (j + 1 != n) {
                        if (seats[i][j + 1] == '.') seats[i][j + 1] = i * 10 + j;
                        if (i + 1 != m && seats[i + 1][j + 1] == '.') seats[i + 1][j + 1] = i * 10 + j;
                    }
                    maxStudents(seats, ret, cur + 1, i, j);
                    if (j + 1 != n) {
                        if (seats[i][j + 1] == i * 10 + j) seats[i][j + 1] = '.';
                        if (i + 1 != m && seats[i + 1][j + 1] == i * 10 + j) seats[i + 1][j + 1] = '.';
                    }
                    if (j != 0) {
                        if (seats[i][j - 1] == i * 10 + j) seats[i][j - 1] = '.';
                        if (i != 0 && seats[i - 1][j - 1] == i * 10 + j) seats[i - 1][j - 1] = '.';
                    }
                    seats[i][j] = '.';
                }
            }
        }
        ret = max(ret, cur);
    }
};

/*
[["#",".",".",".","#"],
 [".","#",".","#","."],
 [".",".","#",".","."],
 [".","#",".","#","."],
 ["#",".",".",".","#"]]
*/

/*
[[".","#",".",".","."],
 [".","#",".","#","."],
 ["#","#",".",".","#"],
 ["#",".","#","#","."],
 ["#",".","#",".","#"]]
*/
