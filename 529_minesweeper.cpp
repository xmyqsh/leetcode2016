class Solution {
public:
    vector<vector<char>> updateBoard(vector<vector<char>>& board, vector<int>& click) {
        if (board[click[0]][click[1]] == 'M') {
            board[click[0]][click[1]] = 'X';
            return board;
        }
        clickFunc(board, click[0], click[1]);
        return board;
    }
    void clickFunc(vector<vector<char>>& board, int x, int y) {
        if (x == -1 || x == board.size() || y == -1 || y == board[0].size()) return;
        if (board[x][y] == 'E') {
            int cnt = 0;
            for (int i = x - 1; i <= x + 1; ++i) {
                for (int j = y - 1; j <= y + 1; ++j) {
                    if (i == -1 || i == board.size() || j == -1 || j == board[0].size()) continue;
                    if (board[i][j] == 'M') ++cnt;
                }
            }
            if (cnt) board[x][y] = cnt + '0';
            else {
                board[x][y] = 'B';
                for (int i = x - 1; i <= x + 1; ++i)
                    for (int j = y - 1; j <= y + 1; ++j)
                        clickFunc(board, i, j);
            }
        }
    }
};
